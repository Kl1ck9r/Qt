cmake_minimum_required(VERSION 3.24.1) 
									
project(Snake LANGUAGES CXX)				

set(SOURCE_EXE main.cpp)			

file(GLOB_RECURSE Snake_HEADERS ${PROJECT_SOURCE_DIR}/include*.h)
file(GLOB_RECURSE Snake_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(Snake
	${Snake_HEADERS}
	${Snake_SOURCES}
	)
	
target_include_directories(Snake PRIVATE include/)