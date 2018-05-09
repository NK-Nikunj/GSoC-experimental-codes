# Implementation as a Header

This directory contains the experimental code for the implementation of my GSoC
Project.

The code above is meant to alter the working of an executable by changing the
entry point of compiler's version of main with my own implementation that I
like to call ``initialize_main``.


## Executable Reproduction

The code has been verified to be working on clang and gcc on Ubuntu.
To reproduce the same, we need to first create a shared object file using:

```
:~GSoC-experimental-codes/normal_code/as_header$ (COMPILER) -shared -fPIC \
-Wall -o hooking_part.so hooking_part.cpp -ldl
```

The above command should create hooking_part.so which will be needed to call
with the executable created with execution.cpp.

Now, that we have the hooking_part.so, we will now create the executable using:

```
:~GSoC-experimental-codes/normal_code/as_header$ (COMPILER) executable.cpp \
-o executable_(COMPILER)
```

To run the executable, we will make use of LD_PRELOAD. Command for the same:
```
:~GSoC-experimental-codes/normal_code/as_header$ LD_PRELOAD=./hooking_part.so \
./executable_(COMPILER)
```

This should result in:
```
:~GSoC-experimental-codes/normal_code/as_header$ LD_PRELOAD=./hooking_part.so \
./executable_(COMPILER)
This is the compiler main now!
This is now called by our version of main
:~GSoC-experimental-codes/normal_code/as_header$
```