//
// Created by maddock on 1/2/26.
//

#include "VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_ID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_ID);
}

void VertexArray::addBuffer(const VertexBuffer &vbo, const VertexBufferLayout &layout) const {
    bind();
    vbo.bind();

    const std::vector<VertexBufferLayoutElement> &elements = layout.getElements();

    unsigned int offset = 0;

    for (unsigned int i = 0; i < elements.size(); i++) {
        const auto &[type, count, normalized] = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, static_cast<GLint>(count), type, normalized, static_cast<GLsizei>(layout.getStride()),
                              reinterpret_cast<void *>(offset));

        offset += count * VertexBufferLayoutElement::getTypeSize(type);
    }
}


void VertexArray::bind() const {
    glBindVertexArray(m_ID);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}
