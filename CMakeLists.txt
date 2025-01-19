cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(texceditor VERSION 1.0)

# Add the executable
add_executable(texceditor src/main.c)

# Include raylib headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link raylib library
target_link_libraries(texceditor ${CMAKE_SOURCE_DIR}/lib/libraylib.so)

# Add math library for compatibility
target_link_libraries(texceditor m)
