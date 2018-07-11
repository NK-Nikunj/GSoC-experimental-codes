#include <iostream>

extern "C" int __real_main();

extern "C" int __wrap_main () {
    std::cout << __FUNCTION__ << std::endl;
    return __real_main();
}
