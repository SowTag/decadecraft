//
// Created by maddock on 1/1/26.
//

#include "GLFWContext.h"

#include "GLFW/glfw3.h"

GLFWContext::GLFWContext() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
}

GLFWContext::~GLFWContext() {
    glfwTerminate();
}
