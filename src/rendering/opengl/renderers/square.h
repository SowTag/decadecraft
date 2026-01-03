#ifndef SQUARE_RENDERER_H
#define SQUARE_RENDERER_H

#include "../wrappers/VertexArray.h"
#include "../wrappers/VertexBuffer.h"
#include "../wrappers/IndexBuffer.h"
#include "../wrappers/ShaderProgram.h"

class SquareRenderer {
public:
    SquareRenderer();
    void render() const;

private:
    VertexArray m_VAO;
    VertexBuffer m_VBO;
    IndexBuffer m_IBO;
    ShaderProgram m_Shader;
};

#endif // SQUARE_RENDERER_H
