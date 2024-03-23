cmake_minimum_required(VERSION 3.23)
project(Degrees_of_Hell)

set(CMAKE_CXX_STANDARD 14)

add_executable(Degrees_of_Hell main.cpp CSpace.h CSpace.cpp CPlayer.cpp CPlayer.h degrees.txt CAssessment.cpp CAssessment.h)
