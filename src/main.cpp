#include "rendering/glfw/Window.h"

int main() {
    const Window window(800, 600, "Decadecraft");

    while (window.shouldStayOpen()) {


        window.swapBuffers();
        Window::pollEvents();
    }

    return 0;
}
