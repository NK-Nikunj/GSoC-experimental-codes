// Copyright (c) 2018 Nikunj Gupta
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// This is a working implementation of hpx running directly from main
#include "initialize_hpx.hpp"
#include <hpx/hpx_init.hpp>

int universal_ans()
{
	return 42;
}

int main (int argc, char** argv)
{
	
	hpx::future<int> found_solution = hpx::async(&universal_ans);

	std::cout << "We are currently making use of hpx functionaity from main" << std::endl;

	int ans = found_solution.get();
	std::cout << "Answer is always: " << ans << " ;)" << std::endl;
	return hpx::finalize();
}