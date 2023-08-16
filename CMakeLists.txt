cmake_minimum_required (VERSION 3.26.4)
project (Maths)
set(CMAKE_CXX_STANDARD 20)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON) 

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options("-O3")
endif()
# add_compile_options("--save-temps")
# add_compile_options("-fverbose-asm")


include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src") 
add_executable(Vector tests/Vector.cpp src/Maths.cpp)
add_executable(Performance tests/Performance/Performance.cpp src/Maths.cpp)

include(CTest)
add_test(NAME Vector COMMAND Vector)