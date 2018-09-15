cmake_minimum_required(VERSION 3.9)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 11)

add_executable(AbstractVM
        main.cpp
        IOperand.cpp
        Operand.hpp
        OperandFactory.cpp
        Parser.cpp
        Lexer.cpp
        AvmException.hpp)
