cmake_minimum_required (VERSION 3.0)

target_include_directories (${CMAKE_PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources (${CMAKE_PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/filemodel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main_window_model.cpp
)
