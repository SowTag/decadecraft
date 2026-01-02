//
// Created by maddock on 1/1/26.
//

#ifndef DECADECRAFT_GLFWCONTEXT_H
#define DECADECRAFT_GLFWCONTEXT_H


class GLFWContext {
public:
    GLFWContext();
    ~GLFWContext();

    GLFWContext(const GLFWContext&) = delete;
    GLFWContext& operator=(const GLFWContext&) = delete;
};


#endif //DECADECRAFT_GLFWCONTEXT_H