cmake_minimum_required (VERSION 3.26.4)
project (Maths)
set(CMAKE_CXX_STANDARD 20)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON) 

set(CMAKE_CXX_FLAGS "-O3")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src") 
add_executable(Vector tests/Vector.cpp src/Maths.cpp)

include(CTest)
add_test(NAME Vector COMMAND Vector)