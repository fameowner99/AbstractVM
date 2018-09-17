cmake_minimum_required(VERSION 3.9)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 11)

add_executable(AbstractVM
        src/Lexer.cpp
        src/main.cpp
        src/OperandFactory.cpp
        src/Parser.cpp)
