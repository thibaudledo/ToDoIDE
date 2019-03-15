cmake_minimum_required(VERSION 3.0.0)

project("ToDoIDE" VERSION 1.0 LANGUAGES CXX)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} "")

add_subdirectory(src)

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::Widgets)
