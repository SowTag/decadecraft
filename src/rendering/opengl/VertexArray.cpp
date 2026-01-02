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

void VertexArray::bind() const {
    glBindVertexArray(m_ID);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}
