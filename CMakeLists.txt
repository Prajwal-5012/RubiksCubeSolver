cmake_minimum_required(VERSION 3.25)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver main.cpp RubikCube.cpp RubikCube.h RubiksCube3DArray.cpp RubiksCube1DArray.cpp RubiksCubeBitboard.cpp Solver/DFSSolver.h Solver/BFSSolver.h Solver/IDDFSSolver.h)
