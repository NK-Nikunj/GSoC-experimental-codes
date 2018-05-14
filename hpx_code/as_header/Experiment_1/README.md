# Experiment 1

This directory contains the working code for HPX directly running from compiler's main.

## How to reproduce the same binary?

To run the experiment (currently tested only on Ubuntu 18.04 LTS), create a build directory using:

```
$ mkdir build && cd build
```

Now, run:
```
$ cmake -DHPX_DIR=$HPX_LOCATION/lib/cmake/HPX ..
$ make
```

This should result in a binary with the name of **hpx_experiment_1**. To run the same, use:

```
$ ./hpx_experiment_1
```


## How does it work?

This experiment makes use of ``dlfcn`` library (as apparent from the normal_code directory). I'm directly setting a hook to the ``__libc_start_main`` which is responsible for starting the initialization sequence (by calling respective functions) and then finally calling ``int main`` (or Compiler's main).

Using this hook, I'm changing the call from ``int main`` to my own custom implementation ``int initializing_main``. This would mean that after setting up the initialization sequence the compiler will call our custom main instead of ``int main``.

In ``int initializing_main``, I start the HPX runtime system by using hpx::init().


## Potential Pitfalls

* Using ``struct`` at global scope and initializing it's member at global scope would produce runtime errors (provided the ``struct`` contains function calls defined only in hpx runtime system). This is because the runtime system is initialized after the _struct object_ is created.

* The method can only work for ``int main(int argc, char** argv)``.