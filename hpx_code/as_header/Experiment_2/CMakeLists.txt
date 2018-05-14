# Copyright (c) 2018 Nikunj Gupta
#
#  Distributed under the Boost Software License, Version 1.0. (See accompanying
#  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(experiment_2 CXX)

find_package(HPX REQUIRED)

add_hpx_executable(hpx_experiment_2
	ESSENTIAL
	SOURCES hpx_experiment_2.cpp
	HEADERS initialize_hpx.hpp
	COMPONENT_DEPENDENCIES iostreams)