//
// Created by maddock on 1/2/26.
//

#ifndef DECADECRAFT_VERTEXBUFFERLAYOUT_H
#define DECADECRAFT_VERTEXBUFFERLAYOUT_H

#include <vector>
#include <glad/gl.h>
#include <cassert>

struct VertexBufferLayoutElement {
    unsigned int type;
    unsigned int count;
    bool normalized;

    static unsigned int getTypeSize(unsigned int type) {
        switch (type) {
            case GL_FLOAT: return sizeof(GLfloat);
            case GL_UNSIGNED_INT: return sizeof(GLuint);
            case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
            default: assert(false); return 0;
        }
    }
};

class VertexBufferLayout {
public:
    VertexBufferLayout();
    ~VertexBufferLayout() = default;

    template<typename T>
    void push(unsigned int count) { static_assert(sizeof(T) == 0, "Unsupported type for push"); }

    [[nodiscard]] const std::vector<VertexBufferLayoutElement>& getElements() const { return m_Elements; }
    [[nodiscard]] unsigned int getStride() const { return m_Stride; }

private:
    std::vector<VertexBufferLayoutElement> m_Elements;
    unsigned int m_Stride;
};

template<>
void VertexBufferLayout::push<float>(unsigned int count);

template<>
void VertexBufferLayout::push<unsigned int>(unsigned int count);

template<>
void VertexBufferLayout::push<unsigned char>(unsigned int count);

#endif //DECADECRAFT_VERTEXBUFFERLAYOUT_H
