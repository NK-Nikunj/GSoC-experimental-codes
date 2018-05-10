# Implementation as a Header

This directory contains the experimental code for the implementation of my GSoC
Project.

The code above is meant to alter the working of an executable by changing the
entry point of compiler's version of main with my own implementation that I
like to call ``initialize_main``.


## Executable Reproduction

``NOTE: Replace (COMPILER) with compiler name everywhere``

The code has been verified to be working on clang and gcc on Ubuntu.
To reproduce the same, we need to first create a shared object file using:

```
:~GSoC-experimental-codes/normal_code/as_header$ (COMPILER) -shared -fPIC \
	-Wall -o hooking_part_(COMPILER).so hooking_part.cpp -ldl
```

The above command should create hooking_part_(COMPILER).so which will be 
needed to call with the executable created with execution.cpp.

Now, that we have the hooking_part_(COMPILER).so, we will now create the executable using:

```
:~GSoC-experimental-codes/normal_code/as_header$ (COMPILER) executable.cpp \
	-o executable_(COMPILER)
```

To run the executable, we will make use of ``LD_PRELOAD``. Command for the same:

```
:~GSoC-experimental-codes/normal_code/as_header$ LD_PRELOAD=./hooking_part.so \
	./executable_(COMPILER)
```

This should result in:

```
:~GSoC-experimental-codes/normal_code/as_header$ LD_PRELOAD=./hooking_part_(COMPILER).so \
	./executable_(COMPILER)
This is the compiler main now!
This is now called by our version of main
:~GSoC-experimental-codes/normal_code/as_header$
```

## Experiment Number 1

Adding an example from the HPX build and using ``LD_PRELOAD`` with it. 
Considering gcc build of HPX and taking fibonaaci as an example, run:

```
:~GSoC-experimental-codes/normal_code/as_header$ LD_PRELOAD=./hooking_part_gcc.so \
	./fibonacci
This is the compiler main now!
fibonacci(10) == 55
elapsed time: 0.001660 [s]
:~GSoC-experimental-codes/normal_code/as_header$
```

As seen from the output, custom main implementation still works elegantly.

## Experiment Number 2

This time clang build of HPX is considered and quicksort is taken as an 
example. Command for the same is given by:

```
:~GSoC-experimental-codes/normal_code/as_header$ LD_PRELOAD=./hooking_part_clang.so \
	./quicksort
This is the compiler main now!
serial quicksort
  elapsed=6.664e-05
  count=1747
parallel quicksort
  elapsed=0.0102904
  count=1726
:~GSoC-experimental-codes/normal_code/as_header$
```

Again, custom main implementation works and the output is as expected.