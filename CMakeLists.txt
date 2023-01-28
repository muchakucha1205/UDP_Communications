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
add_executable(tx tx.cpp )
add_executable(rx rx.cpp )

## target link
target_link_libraries(tx ws2_32.dll)
target_link_libraries(rx ws2_32.dll)
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

target_compile_definitions(tx PUBLIC DEBUG_ENABLE)
target_compile_definitions(tx PUBLIC IP_ADDRESS="127.0.0.1")
target_compile_definitions(tx PUBLIC PORT_NUMBER=50008)
target_compile_definitions(rx PUBLIC DEBUG_ENABLE)
target_compile_definitions(rx PUBLIC IP_ADDRESS="127.0.0.1")
target_compile_definitions(rx PUBLIC PORT_NUMBER=50008)