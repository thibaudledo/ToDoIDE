target_sources(${CMAKE_PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/main_window.h
        ${CMAKE_CURRENT_SOURCE_DIR}/main_window.cpp)

add_subdirectory(component_interface)
