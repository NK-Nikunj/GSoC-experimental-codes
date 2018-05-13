cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(your_app CXX)

find_package(HPX REQUIRED)

add_hpx_executable(hpx_execution_gcc
	ESSENTIAL
	SOURCES hpx_execution.cpp
	HEADERS initialize_hpx.hpp
	COMPONENT_DEPENDENCIES iostreams)