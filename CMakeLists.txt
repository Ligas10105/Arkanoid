cmake_minimum_required(VERSION 3.24)
project(Arkanoid)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Arkanoid main.cpp Colission.cpp)

target_link_libraries(Arkanoid PRIVATE sfml-graphics)
target_compile_features(Arkanoid PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Arkanoid POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Arkanoid> $<TARGET_FILE_DIR:Arkanoid> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Arkanoid)
