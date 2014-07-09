cmake_minimum_required (VERSION 2.6)
project(nunya)
set(warnings "-W -Wall -Wextra -Wshadow -pedantic")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	
include_directories(${PROJECT_SOURCE_DIR}/modules)

function(makeNunyaLibrary libName)
	aux_source_directory(${PROJECT_SOURCE_DIR}/modules/${libName} LOCAL_SRC)
	add_library(${libName} STATIC ${LOCAL_SRC})
endfunction()

makeNunyaLibrary(chrono)
makeNunyaLibrary(except)
makeNunyaLibrary(gui)
makeNunyaLibrary(gui.sfml)
makeNunyaLibrary(logger)
makeNunyaLibrary(str)

