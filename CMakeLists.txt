cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(main CXX)
message("---------------Debug Message---------------")
message(${PROJECT_NAME})
message(${PROJECT_SOURCE_DIR})
message("---------------Debug Message---------------")

set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

# set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wfatal-errors -Wundef")
# set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
# set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set the project name and language.

add_executable(tx send.cpp )
add_executable(rx receive.cpp )

## target link

# add_subdirectory(common)
# target_link_libraries(${PROJECT_NAME} common)
# add_subdirectory(func1)
# target_link_libraries(${PROJECT_NAME} func1)

## include dirctories

# target_include_directories(
#     ${PROJECT_NAME}
#     PUBLIC
#     "C:\\common\\Eigen"
#     ${PROJECT_SOURCE_DIR}/common/include
#     ${PROJECT_SOURCE_DIR}/func1/include
# )

## #defineの追加
# global
# add_compile_definitions(ALL_DEBUG_ENABLE)
## targetのみ

# target_compile_definitions(${PROJECT_NAME} PUBLIC DEBUG_ENABLE)