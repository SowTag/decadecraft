//
// Created by maddock on 1/2/26.
//

#ifndef DECADECRAFT_ENGINE_H
#define DECADECRAFT_ENGINE_H

#define DECADECRAFT_DEBUG true

#include "../rendering/glfw/Window.h"
#include "../rendering/opengl/renderers/square.h"

class Engine {
public:
    Engine();
    ~Engine();

    void init();
    void run() const;

private:
    Window m_Window;

    SquareRenderer temp_SquareRenderer;
};


#endif //DECADECRAFT_ENGINE_H