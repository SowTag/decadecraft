//
// Created by maddock on 1/2/26.
//

#ifndef DECADECRAFT_VERTEXBUFFER_H
#define DECADECRAFT_VERTEXBUFFER_H


class VertexBuffer {
public:
    VertexBuffer(const void *data, unsigned int size, unsigned int usage = GL_STATIC_DRAW);

    ~VertexBuffer();

    void bind() const;

    static void unbind();

private:
    unsigned int m_ID{};
};


#endif //DECADECRAFT_VERTEXBUFFER_H
