#include <iostream>

// This is the actual libc function that we will call from our wrapper function
extern "C" int __real___libc_start_main (
				int (*main)(int, char**, char**), int argc, char **argv,
				void (*init) (void), void (*fini) (void),
				void (*rtld_fini) (void), void (* stack_end));

// Storing pointer to main
int (*actual_main)(int, char**, char**) = nullptr;

// Our custom entry point
int initialize_main(int argc, char** argv, char** envp)
{
    std::cout << __FUNCTION__ << std::endl;

    // Calling the C main function from our entry point
    return actual_main(argc, argv, envp);
}

int (*custom_main)(int, char**, char**) = &initialize_main;

// Our wrapper for the libc function
extern "C" int __wrap___libc_start_main (
				int (*main)(int, char**, char**), int argc, char **argv,
				void (*init) (void), void (*fini) (void),
				void (*rtld_fini) (void), void (* stack_end))
{

    // Assigning the value of main to actual_main
    actual_main = main;

	// calling original __libc_start_main, but with our custom entry point implementation
	return __real___libc_start_main(custom_main, argc, argv, init, fini, rtld_fini, stack_end);
}
