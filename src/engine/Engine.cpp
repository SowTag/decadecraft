//
// Created by maddock on 1/2/26.
//

#include "Engine.h"

#include "../rendering/glfw/Window.h"

Engine::Engine() : m_Window(800, 600, "Decadecraft") {

}

Engine::~Engine() = default;

void Engine::init() {
}

void Engine::run() const {
    while (m_Window.shouldStayOpen()) {
        m_Window.swapBuffers();
        Window::pollEvents();
    }
}
