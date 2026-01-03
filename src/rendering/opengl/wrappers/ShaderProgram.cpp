//
// Created by maddock on 1/2/26.
//

#include "ShaderProgram.h"

#include <glad/gl.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

static std::string loadShaderSource(const std::string &filepath) {
    std::ifstream fileStream(filepath);
    if (!fileStream.is_open()) {
        std::cerr << "Failed to open shader file: " << filepath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}


static unsigned int compileShader(const std::string &source, const unsigned int type) {
    const unsigned int shader = glCreateShader(type);

    const char *src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int compilationResult;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationResult);

    if (compilationResult == GL_FALSE) {
        int infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

        std::vector<char> message(infoLogLength);
        glGetShaderInfoLog(shader, infoLogLength, &infoLogLength, message.data());

        std::cerr << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" <<
                std::endl;
        std::cerr << message.data() << std::endl;

        glDeleteShader(shader);
        return 0;
    }

    return shader;
}


ShaderProgram::ShaderProgram(ShaderProgramSourcePaths sourcePaths)
    : m_ID(0), m_SourcePaths(std::move(sourcePaths)) {
    compile();
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(m_ID);
}

void ShaderProgram::bind() const {
    glUseProgram(m_ID);
}

void ShaderProgram::unbind() {
    glUseProgram(0);
}

void ShaderProgram::setUniform4f(const std::string &name, const float v0, const float v1, const float v2,
                                 const float v3) const {
    glUniform4f(getCachedUniformLocation(name), v0, v1, v2, v3);
}

int ShaderProgram::getCachedUniformLocation(const std::string &name) const {
    if (m_uniformLocationCache.contains(name)) {
        return m_uniformLocationCache[name];
    }

    const int location = glGetUniformLocation(m_ID, name.c_str());
    if (location == -1) {
        std::cerr << "Warning: uniform " << name << " doesn't exist" << std::endl;
    }

    m_uniformLocationCache[name] = location;
    return location;
}

void ShaderProgram::compile() {
    const std::string vertexShaderSource = loadShaderSource(m_SourcePaths.vertexShaderSourcePath);
    const std::string fragmentShaderSource = loadShaderSource(m_SourcePaths.fragmentShaderSourcePath);

    if (vertexShaderSource.empty() || fragmentShaderSource.empty()) {
        return;
    }

    const unsigned int program = glCreateProgram();
    const unsigned int vs = compileShader(vertexShaderSource, GL_VERTEX_SHADER);
    const unsigned int fs = compileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

    if (vs == 0 || fs == 0) {
        return;
    }

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    int isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE) {
        int maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<char> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, infoLog.data());

        std::cerr << "Shader Program link error: " << infoLog.data() << std::endl;

        glDeleteProgram(program);
        glDeleteShader(vs);
        glDeleteShader(fs);
        return;
    }

    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    m_ID = program;
}
