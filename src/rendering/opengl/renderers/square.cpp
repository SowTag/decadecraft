//
// Created by maddock on 1/3/26.
//

#include "square.h"
#include "../wrappers/VertexBufferLayout.h"
#include <glad/gl.h>

static constexpr float positions[] = {
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.5f, 0.5f,
    -0.5f, 0.5f
};

static constexpr unsigned int indices[] = {
    0, 1, 2,
    2, 3, 0
};

SquareRenderer::SquareRenderer()
    : m_VBO(positions, sizeof(positions)),
      m_IBO(indices, 6),
      m_Shader(ShaderProgramSourcePaths{
          "assets/shaders/square/square.vert",
          "assets/shaders/square/square.frag"
      }) {
    VertexBufferLayout layout;
    layout.push<float>(2);
    m_VAO.addBuffer(m_VBO, layout);
}

void SquareRenderer::render() const {
    m_Shader.bind();
    m_VAO.bind();
    m_IBO.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}
