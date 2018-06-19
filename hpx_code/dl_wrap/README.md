# Implementation with Wl,-wrap

This directory contains the experimental code for the implementation of my GSoC
Project.

The code above is meant to alter the working of an executable by changing the
entry point of compiler's version of main with my own implementation that I
like to call ``initialize_main``.

## Executable Reproduction

This directory contains a makefile to execute. It can produce dynamically linked executable.

Run:
```
$ make
```

This should generate the executable `dynamic`. To run it:

```
$ ./dynamic
```

The expected output should be:

```
$ ./dynamic
Trying
From struct: 42
42
```
