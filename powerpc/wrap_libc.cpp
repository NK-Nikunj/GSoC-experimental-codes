#include <iostream>
#include <elf.h>
#include <sys/types.h>

#define ElfW(type)	_ElfW (Elf, __ELF_NATIVE_CLASS, type)
#define _ElfW(e,w,t)	_ElfW_1 (e, w, _##t)
#define _ElfW_1(e,w,t)	e##w##t

// #include <bits/elfclass.h>
#include <link.h>

// This is the actual libc function that we will call from our wrapper function
extern "C" int __real___libc_start_main (int argc, char **argv,
		   char **ev,
		   ElfW (auxv_t) * auxvec,
		   void (*rtld_fini) (void),
		   struct startup_info *stinfo,
		   char **stack_on_entry);

// Storing pointer to main
int (*actual_main)(int, char**, char**, void*) = nullptr;

// Our custom entry point
int initialize_main(int argc, char** argv, char** envp, void* abc)
{
    std::cout << __FUNCTION__ << std::endl;

    // Calling the C main function from our entry point
    return actual_main(argc, argv, envp, abc);
}

struct startup_info
  {
    void *sda_base;
    int (*main) (int, char **, char **, void *);
    int (*init) (int, char **, char **, void *);
    void (*fini) (void);
  };

int __wrap___libc_start_main (int argc, char **argv,
		   char **ev,
		   ElfW (auxv_t) * auxvec,
		   void (*rtld_fini) (void),
		   struct startup_info *stinfo,
		   char **stack_on_entry)
{
	// Assigning the value of main to actual_main
    actual_main = stinfo -> main;
	stinfo -> main = &initialize_main;

	// calling original __libc_start_main, but with our custom entry point implementation
	return __real___libc_start_main(argc, argv, ev, auxvec, rtld_fini, stinfo, stack_on_entry);
}
