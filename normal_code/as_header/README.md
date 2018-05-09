# Implementation as a Header

This directory contains the experimental code for the implementation of my GSoC
Project.

The code above is meant to alter the working of an executable by changing the
entry point of compiler's version of main with my own implementation that I
like to call ``initialize_main``.


## Executable Reproduction

The code has been verified to be working on clang and gcc on Ubuntu.
To reproduce the same working executables, use:

```
:~GSoC-experimental-codes/normal_code/as_header$ (COMPILER) -o execution_(COMPILER) execution.cpp -fPIC -Wall -ldl
```

Just replace the (COMPILER) with the compiler you are using. For eg:

```
:~GSoC-experimental-codes/normal_code/as_header$ g++ -o execution_gcc execution.cpp -fPIC -Wall -ldl
```
