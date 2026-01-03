cmake_minimum_required(VERSION 4.1)
project(decadecraft)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_executable(decadecraft src/main.cpp
        src/rendering/glfw/Window.cpp
        src/rendering/glfw/Window.h
        src/debug/tracing.h
        src/rendering/opengl/wrappers/VertexArray.cpp
        src/rendering/opengl/wrappers/VertexArray.h
        src/rendering/opengl/wrappers/VertexBuffer.cpp
        src/rendering/opengl/wrappers/VertexBuffer.h
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/debug/opengl.h
        src/rendering/opengl/wrappers/VertexBufferLayout.cpp
        src/rendering/opengl/wrappers/VertexBufferLayout.h
        src/rendering/opengl/wrappers/IndexBuffer.cpp
        src/rendering/opengl/wrappers/IndexBuffer.h
        src/rendering/opengl/wrappers/ShaderProgram.cpp
        src/rendering/opengl/wrappers/ShaderProgram.h
        src/rendering/opengl/renderers/square.cpp
)


include(GLAD)
include(GLFW)
include(GLM)

include(PCH)        # precompiled headers


target_link_libraries(decadecraft PRIVATE
        glad
        glfw
        glm
)

add_custom_command(TARGET decadecraft POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets
        COMMENT "Copying assets to output directory")

include(CompilerOptions)
