//
// Created by maddock on 1/1/26.
//

#ifndef DECADECRAFT_GLFWCONTEXT_H
#define DECADECRAFT_GLFWCONTEXT_H


class Window {
public:
    Window(unsigned int width, unsigned int height, const char* title);

    ~Window();

    [[nodiscard]] bool shouldStayOpen() const;

    void swapBuffers() const;

    static void pollEvents();

    [[nodiscard]] GLFWwindow *getWindowPtr() const { return m_Window; }

    Window(const Window &) = delete;

    Window &operator=(const Window &) = delete;

private:
    GLFWwindow *m_Window{};
};


#endif //DECADECRAFT_GLFWCONTEXT_H
