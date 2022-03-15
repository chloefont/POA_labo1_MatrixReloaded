cmake_minimum_required(VERSION 3.19)
project(POA_labo1_MatrixReloaded)

set(CMAKE_CXX_STANDARD 11)

add_executable(POA_labo1_MatrixReloaded main.cpp operations/Operation.h operations/Operation.cpp operations/Add.cpp operations/Add.h operations/Sub.cpp operations/Sub.h operations/Mult.cpp operations/Mult.h Matrix.cpp Matrix.h Application.cpp Application.h tests/Tests.cpp tests/Tests.h)
add_executable(POA_labo1_MatrixReloaded_tests operations/Operation.h
        operations/Operation.cpp operations/Add.cpp operations/Add.h operations/Sub.cpp operations/Sub.h operations/Mult.cpp operations/Mult.h Matrix.cpp Matrix.h Application.cpp Application.h tests/Tests.cpp tests/Tests.h tests/mainTests.cpp)