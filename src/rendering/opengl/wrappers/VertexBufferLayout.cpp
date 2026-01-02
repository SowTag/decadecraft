//
// Created by maddock on 1/2/26.
//

#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout() : m_Stride(0) {}

template<>
void VertexBufferLayout::push<float>(const unsigned int count) {
    m_Elements.push_back({GL_FLOAT, count, false});
    m_Stride += count * VertexBufferLayoutElement::getTypeSize(GL_FLOAT);
}

template<>
void VertexBufferLayout::push<unsigned int>(const unsigned int count) {
    m_Elements.push_back({GL_UNSIGNED_INT, count, false});
    m_Stride += count * VertexBufferLayoutElement::getTypeSize(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::push<unsigned char>(const unsigned int count) {
    m_Elements.push_back({GL_UNSIGNED_BYTE, count, true});
    m_Stride += count * VertexBufferLayoutElement::getTypeSize(GL_UNSIGNED_BYTE);
}
