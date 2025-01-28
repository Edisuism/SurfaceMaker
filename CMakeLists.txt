cmake_minimum_required(VERSION 3.10)
project(testSurface)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Source files
set(SOURCES
    main.cpp
)

# Source files
set(HEADERS
    SurfaceMaker.h
    DrT.h 
    tetgen.h
)

# Add executable
add_executable(testSurface ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(testSurface PRIVATE ${CMAKE_SOURCE_DIR}/lib/libCycleDiscovery.a PRIVATE ${CMAKE_SOURCE_DIR}/lib/libMWT_v5.a PRIVATE ${CMAKE_SOURCE_DIR}/lib/libtet.a) 

