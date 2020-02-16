cmake_minimum_required(VERSION 3.0)
project(CJSONExample)

file(COPY ${PROJECT_SOURCE_DIR}/json DESTINATION ${PROJECT_SOURCE_DIR}/build)

add_executable(${CMAKE_PROJECT_NAME} "${PROJECT_SOURCE_DIR}/main.cpp")