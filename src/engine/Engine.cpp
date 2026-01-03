//
// Created by maddock on 1/2/26.
//

#include "Engine.h"

#include "../rendering/glfw/Window.h"
#include "GLFW/glfw3.h"

Engine::Engine() : m_Window(800, 600, "Decadecraft") {

}

Engine::~Engine() = default;

void Engine::init() {

}

void Engine::run() const {
    double lastFrameTime = glfwGetTime();

    while (m_Window.shouldStayOpen()) {
        const double currentFrameTime = glfwGetTime();
        auto deltaTime = static_cast<float>(currentFrameTime - lastFrameTime);
        lastFrameTime = currentFrameTime;

        // update stuff
        temp_SquareRenderer.render();

        m_Window.swapBuffers();
        Window::pollEvents();
    }
}
