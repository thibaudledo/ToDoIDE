cmake_minimum_required(VERSION 3.0.0)

project("ToDoIDE" VERSION 1.0 LANGUAGES CXX)

add_custom_target (debug
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=debug ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
    COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
)

add_custom_target (release
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=release ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
    COMMENT "Switch CMAKE_BUILD_TYPE to Release"
)

add_custom_target (run COMMAND ${CMAKE_PROJECT_NAME}
    COMMENT "Run with ${CMAKE_BUILD_TYPE} configuration"
)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} "")

add_subdirectory(src)

set_target_properties (${CMAKE_PROJECT_NAME}
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}"
)

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::Widgets)
