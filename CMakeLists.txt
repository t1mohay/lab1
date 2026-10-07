cmake_minimum_required(VERSION 3.23)
project(cpp_lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab1 src/main.cpp)

enable_testing()
add_test(NAME lab1_run COMMAND lab1)
