/* This file is meant to be a sharable object file	*/

// Not necessary, but, added for portability purposes
#define _GNU_SOURCE		

// For using dlsym()
#include <dlfcn.h>		
#include <iostream>	

// To store the pointer to the compiler's version of main 
int (*actual_main)(int, char**, char**);

// This function makes the above pointer point to compiler's version of main
void assign (int (*main)(int, char**, char**))
{
	actual_main = main;
}


// This is the main entry point now instead of "int main"
int initializing_main (int argc, char** argv, char** envp)
{
	std::cout << "This is the compiler main now!" << std::endl;
	
	// This function will now call "int main". Therefore, int main is no longer
	// the entry point
	return actual_main(argc, argv, envp);
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
	
	// Calling assign function to store the pointer to compiler's main
	assign(main);

	// call original __libc_start_main, but replace "main" with our custom implementation
	return real_start_main(initializing_main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}