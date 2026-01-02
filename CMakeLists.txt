cmake_minimum_required(VERSION 4.1)
project(decadecraft)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_executable(decadecraft src/main.cpp
        src/rendering/glfw/GLFWContext.cpp
        src/rendering/glfw/GLFWContext.h
        src/debug/tracing.h
)


include(GLAD)
include(GLFW)

include(PCH)        # precompiled headers


target_link_libraries(decadecraft PRIVATE
        glad
        glfw
)

include(CompilerOptions)