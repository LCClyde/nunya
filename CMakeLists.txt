cmake_minimum_required (VERSION 2.6)
project(nunya)
set(warnings "-W -Wall -Wextra -Wshadow -pedantic")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -O0 -g")
link_directories(${CMAKE_BINARY_DIR}/lib ${CMAKE_BINARY_DIR}/third_party/sfml64/lib)
	
include_directories(${PROJECT_SOURCE_DIR}/modules)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/tests)
add_executable(_clyde tests/_clyde.cpp)
target_link_libraries(_clyde gui.sfml gui)

function(makeNunyaLibrary libName)
	aux_source_directory(${PROJECT_SOURCE_DIR}/modules/${libName} LOCAL_SRC)
	add_library(${libName} STATIC ${LOCAL_SRC})
endfunction()

makeNunyaLibrary(chrono)

makeNunyaLibrary(except)

makeNunyaLibrary(graphics.sfml)

makeNunyaLibrary(gui)
target_link_libraries(gui except str)

makeNunyaLibrary(gui.sfml)
target_link_libraries(gui.sfml gui libsfml-graphics.so libsfml-window.so libsfml-system.so)

makeNunyaLibrary(logger)
target_link_libraries(logger except)

makeNunyaLibrary(str)
target_link_libraries(str except)
