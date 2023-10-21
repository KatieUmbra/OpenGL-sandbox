cmake_minimum_required(VERSION 3.16...3.27)
project(oglpg)

set(ARCHITECTURY 32)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(ARCHITECTURY 64)
endif()

set(CMAKE_BUILD_TYPE Debug)
set(FULL_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}-${ARCHITECTURY}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FULL_OUTPUT_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FULL_OUTPUT_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FULL_OUTPUT_DIR}/bin")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -isystem /usr/local/include/")
add_compile_definitions(SOURCE_DIRECTORY=${CMAKE_SOURCE_DIR})

find_library(glfw NAMES libglfw libglfw3.a PATHS /usr/local/lib)
find_library(glad NAMES libglad glad libglad.a PATHS /usr/local/lib)

set(SOURCE src/Main.cpp)
set(SOURCES
	src/vertex_array.cpp
	src/vertex_buffer.cpp
	src/index_buffer.cpp
	)

add_executable(oglpg ${SOURCE})
add_library(src STATIC ${SOURCES})
target_compile_features(oglpg PUBLIC cxx_std_20)
target_include_directories(oglpg PUBLIC /usr/local/include ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(oglpg PUBLIC ${glfw} ${glad})

target_compile_features(src PUBLIC cxx_std_20)
target_include_directories(src PUBLIC /usr/local/include ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(src PUBLIC ${glfw} ${glad})

target_link_libraries(oglpg PUBLIC src)
