# TODO: Maybe don't hardcode this.
set(GLFW_BUILD_X11 OFF CACHE INTERNAL "")

set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4   # released February 23rd 2024, see https://github.com/glfw/glfw/releases/tag/3.4
)

FetchContent_MakeAvailable(glfw)