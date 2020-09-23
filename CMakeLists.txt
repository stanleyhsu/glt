cmake_minimum_required(VERSION 3.5)
project(gltest)

find_package(OpenGL)
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories($(GLEW_INCLUDE_DIRS))
    link_libraries(${GLEW_LIBRARIES})
endif()

find_package(glfw3  REQUIRED)

add_executable(gltest main.cpp)
target_link_libraries(gltest GLEW::GLEW glfw ${OPENGL_LIBRARIES})