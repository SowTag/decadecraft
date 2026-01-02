//
// Created by maddock on 1/2/26.
//

#ifndef DECADECRAFT_VERTEXARRAY_H
#define DECADECRAFT_VERTEXARRAY_H


class VertexArray {
public:
    VertexArray();

    ~VertexArray();

    void bind() const;

    static void unbind();

private:
    unsigned int m_ID{};
};


#endif //DECADECRAFT_VERTEXARRAY_H
