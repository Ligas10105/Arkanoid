cmake_minimum_required(VERSION 3.24)
project(Arkanoid)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Google Test
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_executable(Arkanoid
        src/main.cpp
        src/Colission.cpp
        src/Ball.h
        src/Ball.cpp
        src/Block.h
        src/Block.cpp
        )

target_link_libraries(Arkanoid PRIVATE sfml-graphics)
target_compile_features(Arkanoid PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Arkanoid POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Arkanoid> $<TARGET_FILE_DIR:Arkanoid> COMMAND_EXPAND_LISTS)
endif ()


install(TARGETS Arkanoid)

# Test executable
add_executable(ArkanoidTests
        test/test_main.cpp
        src/Colission.cpp
        )

target_link_libraries(ArkanoidTests PRIVATE sfml-graphics gtest_main)
target_compile_features(ArkanoidTests PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET ArkanoidTests POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:ArkanoidTests> $<TARGET_FILE_DIR:ArkanoidTests> COMMAND_EXPAND_LISTS)
endif ()

enable_testing()
add_test(NAME ArkanoidTests COMMAND ArkanoidTests)
