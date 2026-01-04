//
// Created by maddock on 1/1/26.
//

#include "Window.h"

#include "GLFW/glfw3.h"

#include "../../engine/Engine.h"
#include "../../debug/opengl.h"

Window::Window(const unsigned int width, const unsigned int height, const char *title) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if DECADECRAFT_DEBUG
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
#endif

    m_Window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), title, nullptr, nullptr);
    if (!m_Window) {
        throw std::runtime_error("Failed to initialize GLFW window");
    }

    glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow */*window*/, const int width, const int height) {
        glViewport(0, 0, width, height);
    });


    glfwMakeContextCurrent(m_Window);

    const int openGLVersion = gladLoadGL(glfwGetProcAddress);
    if (openGLVersion == 0) {
        throw std::runtime_error("Failed to initialize OpenGL context\n");
    }

    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(openGLVersion) << "." << GLAD_VERSION_MINOR(openGLVersion) <<
            std::endl;

#if DECADECRAFT_DEBUG
    enableOpenGLDebug();
#endif
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
