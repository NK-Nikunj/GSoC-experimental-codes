# Implementation with Wl,-wrap

This directory contains the experimental code for the implementation of my GSoC
Project.

The code above is meant to alter the working of an executable by changing the
entry point of compiler's version of main with my own implementation that I
like to call ``initialize_main``.

## Executable Reproduction

This directory contains a makefile to execute. It can produce both statically linked and dynamically linked executable.

Run:
```
$ make
```

This should generate 2 executables namely `static` and `dynamic`. To run any one of them (say `static`):

```
$ ./static
```

The expected output should be:

```
$ ./static
Did it work??
Yes it did!
```
