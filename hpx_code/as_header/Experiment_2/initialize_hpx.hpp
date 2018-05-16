// Copyright (c) 2018 Nikunj Gupta
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

# ifndef INITIALIZE_HPX
#define INITIALIZE_HPX

// Not necessary, but, added for portability purposes
#define _GNU_SOURCE		

// For using dlsym()
#include <dlfcn.h>

// General headers		
#include <iostream>	
#include <vector>

// Adding required HPX headers
#include <hpx/hpx.hpp>


// To store the pointer to the compiler's version of main 
int (*actual_main)(int, char**, char**);
int __argc;
char** __argv;
char** __envp;

// hpx_main is the entry point now for using hpx functionality
// it is now responsible for calling the compiler's main
int hpx_main(boost::program_options::variables_map& vm)
{
	std::cout << "HPX system has been initialized" << std::endl;
	std::cout << "Calling the compiler's main now" << std::endl;

	return actual_main(__argc, __argv, __envp);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// This is the main entry point now instead of "int main"
int initializing_main (int argc, char** argv, char** envp)
{
	std::cout << "This is the compiler main now!" << std::endl;
	
	__argc = argc;
	__argv = argv;
	__envp = envp;

	// Initializing hpx using hpx::init
	return hpx::init(argc, argv);
}
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
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
	
	// Storing pointer to the Compiler's version of main
	actual_main = main;

	// call original __libc_start_main, but replace "main" with our custom implementation
	return real_start_main(initializing_main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif