//
// Created by maddock on 1/1/26.
//

#include "Window.h"

#include "GLFW/glfw3.h"

Window::Window(const unsigned int width, const unsigned int height, const char* title) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    m_Window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), title, nullptr, nullptr);
    if (!m_Window) {
        throw std::runtime_error("Failed to initialize GLFW window");
    }

    glfwMakeContextCurrent(m_Window);

    const int openGLVersion = gladLoadGL(glfwGetProcAddress);
    if (openGLVersion == 0) {
        throw std::runtime_error("Failed to initialize OpenGL context\n");
    }

    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(openGLVersion) << "." << GLAD_VERSION_MINOR(openGLVersion);
}

Window::~Window() {
    glfwTerminate();
}

bool Window::shouldStayOpen() const {
    return !glfwWindowShouldClose(m_Window);
}

void Window::swapBuffers() const {
    glfwSwapBuffers(m_Window);
}

void Window::pollEvents() {
    glfwPollEvents();
}
