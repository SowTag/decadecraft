if(MSVC)
    target_compile_options(decadecraft PRIVATE /W4 /WX)
else() # clang, gcc
    target_compile_options(decadecraft PRIVATE -Wall -Wextra -Wpedantic)
endif()