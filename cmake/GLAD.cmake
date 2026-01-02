FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG v2.0.8    # released September 29th 2024, see https://github.com/Dav1dde/glad/releases/tag/v2.0.8
        SOURCE_SUBDIR cmake
)
FetchContent_MakeAvailable(glad)

glad_add_library(glad STATIC
        REPRODUCIBLE
        API gl:core=4.3
)

set_target_properties(glad PROPERTIES
        EXCLUDE_FROM_ALL ON
        EXCLUDE_FROM_DEFAULT_BUILD OFF
)