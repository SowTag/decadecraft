//
// Created by maddock on 1/2/26.
//

#ifndef DECADECRAFT_ENGINE_H
#define DECADECRAFT_ENGINE_H

#define DECADECRAFT_DEBUG true

#include "../rendering/glfw/Window.h"

class Engine {
public:
    Engine();
    ~Engine();

    void init();
    void run() const;

private:
    Window m_Window;
};


#endif //DECADECRAFT_ENGINE_H