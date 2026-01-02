//
// Created by maddock on 1/2/26.
//

#ifndef DECADECRAFT_INDEXBUFFER_H
#define DECADECRAFT_INDEXBUFFER_H


class IndexBuffer {
public:
    IndexBuffer(const unsigned int *data, unsigned int count);

    ~IndexBuffer();

    void bind() const;

    static void unbind();

private:
    unsigned int m_ID{};
    unsigned int m_Count;
};


#endif //DECADECRAFT_INDEXBUFFER_H
