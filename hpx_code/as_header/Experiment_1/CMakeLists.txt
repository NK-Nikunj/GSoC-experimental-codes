cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(experiment_1 CXX)

find_package(HPX REQUIRED)

add_hpx_executable(hpx_experiment_1
	ESSENTIAL
	SOURCES hpx_experiment_1.cpp
	HEADERS initialize_hpx.hpp
	COMPONENT_DEPENDENCIES iostreams)
