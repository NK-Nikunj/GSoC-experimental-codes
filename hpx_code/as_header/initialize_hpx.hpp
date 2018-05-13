// Copyright (c) 2018 Nikunj Gupta
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Not necessary, but, added for portability purposes
// #define _GNU_SOURCE		

# ifndef INITIALIZE_HPX
#define INITIALIZE_HPX

// For using dlsym()
#include <dlfcn.h>		
#include <iostream>	
#include <vector>

// Including the necessary hpx libraries
#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/util.hpp>

///////////////////////////////////////////////////////////////////////////////
// Prototyping main
int main(int argc, char** argv);
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// This is the main entry point now instead of "int main"
int initializing_main (int argc, char** argv, char** envp)
{
	std::cout << "This is the compiler main now!" << std::endl;
	
	// This function will now call "int main". Therefore, int main is no longer
	// the entry point

	std::vector<std::string> const cfg = {};

	using hpx::util::placeholders::_1;
	using hpx::util::placeholders::_2;

	hpx::util::function_nonser<int(int, char**)> start_function =
		hpx::util::bind(&main, _1, _2);

	return hpx::init(start_function, argc, argv,
						cfg, hpx::runtime_mode_console);

	// return main(argc, argv);
}


// Wrapper for the actual __libc_start_main
extern "C" int __libc_start_main ( 
				int (*main)(int, char**, char**), int argc, char * * ubp_av, 
				void (*init) (void), void (*fini) (void), 
				void (*rtld_fini) (void), void (* stack_end)) 
{
	// Storing pointer to the arguments of __libc_start_main
	int (*real_start_main)(int (*main) (int, char**, char**), int argc, 
		char** ubp_av, void (*init) (void), 
		void (*fini) (void), void (*rtld_fini) (void), void (* stack_end)) 
		= 
		(int (*)(int (*)(int, char**, char**), int, char**, void (*)(), 
		void (*)(), void (*)(), void*))dlsym(RTLD_NEXT, "__libc_start_main");
	

	// call original __libc_start_main, but replace "main" with our custom implementation
	return real_start_main(initializing_main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}
///////////////////////////////////////////////////////////////////////////////
#endif