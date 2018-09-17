cmake_minimum_required(VERSION 3.12)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 14)

add_executable(AbstractVM
        src/Lexer.cpp
        src/main.cpp
        src/OperandFactory.cpp
        src/Parser.cpp)
