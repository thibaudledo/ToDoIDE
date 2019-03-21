cmake_minimum_required (VERSION 3.0)

target_sources(${CMAKE_PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_subdirectory(abstract_class)
add_subdirectory(controller)
add_subdirectory(model)
add_subdirectory(view)
