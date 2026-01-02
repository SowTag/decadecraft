//
// Created by maddock on 1/2/26.
//

#ifndef DECADECRAFT_VERTEXARRAY_H
#define DECADECRAFT_VERTEXARRAY_H
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"


class VertexArray {
public:
    VertexArray();

    ~VertexArray();

    void addBuffer(const VertexBuffer& vbo, const VertexBufferLayout& layout) const;

    void bind() const;

    static void unbind();

private:
    unsigned int m_ID{};
};


#endif //DECADECRAFT_VERTEXARRAY_H
