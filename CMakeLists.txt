cmake_minimum_required(VERSION 3.24)
project(Arkanoid)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

set(SOURCES
        src/main.cpp
        src/Colission.cpp
        src/Ball.h
        src/Ball.cpp
        src/Block.h
        src/Block.cpp
        )

add_executable(Arkanoid ${SOURCES})
target_link_libraries(Arkanoid PRIVATE sfml-graphics)
target_compile_features(Arkanoid PRIVATE cxx_std_17)

set(TEST_SOURCES
        src/Colission.cpp
        src/Ball.h
        src/Ball.cpp
        src/Block.h
        src/Block.cpp
        test/arkanoid_test.cpp
        )

add_executable(ArkanoidTests ${TEST_SOURCES})
target_link_libraries(ArkanoidTests PRIVATE gtest gtest_main sfml-graphics)
target_compile_features(ArkanoidTests PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests(ArkanoidTests)
