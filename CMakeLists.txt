cmake_minimum_required (VERSION 3.26.4)
project (Maths)
set(CMAKE_CXX_STANDARD 20)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON) 

add_compile_options("/O2")
# add_compile_options("-march=native")

# add_compile_options("-S")
# add_compile_options("/FAs")
add_compile_options("--save-temps")
add_compile_options("-fverbose-asm")


include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src") 
# add_executable(Vector tests/Vector.cpp src/Maths.cpp)
add_executable(Performance tests/Performance/Performance.cpp src/Maths.cpp)

include(CTest)
add_test(NAME Vector COMMAND Vector)