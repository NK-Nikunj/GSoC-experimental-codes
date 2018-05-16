# Experiment 2

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

This should result in a binary with the name of **hpx_experiment_2**. To run the same, use:

```
$ ./hpx_experiment_2
```


## What is different in this Experiment

### Upgrades

* Now compiler's main is being __invoked__ by the actual pointer to ``int main``. It is done so at the cost of calling _``hpx::init(argc, argv)``_ from our custom implemented main.

* This header will allow for all possible compiler's main, i.e. ``int main()``, ``int main(int argc, char** argv)`` and ``int main(int argc, char** argv, char** envp)`` as opposed to only ``int main(int argc, char** argv)`` from previous experiment.

### Potential Pitfalls

* Using ``struct`` at global scope and initializing it's member at global scope would produce runtime errors (provided the ``struct`` contains function calls defined only in hpx runtime system). This is because the runtime system is initialized after the _struct object_ is created.

* The initialization code currently makes use of multiple global scope variable. This has to be rectified with a better (and more refined) code overall.