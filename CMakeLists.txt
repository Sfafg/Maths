cmake_minimum_required (VERSION 3.26.4)
project (Maths)

set_property(GLOBAL PROPERTY CXX_STANDARD 20)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON) 

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src") 
add_executable(${PROJECT_NAME} tests/Source.cpp src/Maths.cpp)