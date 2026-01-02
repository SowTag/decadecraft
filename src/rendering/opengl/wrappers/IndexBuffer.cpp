//
// Created by maddock on 1/2/26.
//

#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int *data, const unsigned int count) : m_Count(count) {
    glGenBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_ID);
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(count * sizeof(unsigned int)), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &m_ID);
}

void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void IndexBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
