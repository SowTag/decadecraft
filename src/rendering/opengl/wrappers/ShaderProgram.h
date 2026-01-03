//
// Created by maddock on 1/2/26.
//

#ifndef DECADECRAFT_SHADERPROGRAM_H
#define DECADECRAFT_SHADERPROGRAM_H

#include <string>
#include <unordered_map>

struct ShaderProgramSourcePaths {
    std::string vertexShaderSourcePath;
    std::string fragmentShaderSourcePath;
};

class ShaderProgram {
public:
    explicit ShaderProgram(ShaderProgramSourcePaths sourcePaths);
    ~ShaderProgram();

    void bind() const;
    static void unbind();

    void setUniform4f(const std::string &name, float v0, float v1, float v2, float v3) const;

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;

private:

    unsigned int m_ID;

    const ShaderProgramSourcePaths m_SourcePaths;

    mutable std::unordered_map<std::string, int> m_uniformLocationCache;

    [[nodiscard]] int getCachedUniformLocation(const std::string &name) const;

    void compile();
};


#endif //DECADECRAFT_SHADERPROGRAM_H