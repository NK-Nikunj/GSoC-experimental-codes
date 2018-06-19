#include <iostream>
#include <hpx/hpx.hpp>


int test()
{
    return 42;
}

struct foo {
    foo()
    {
        hpx::future<int> f = hpx::async(&test);
        std::cout << "From struct: " << f.get() << std::endl;
    }

};

foo bar;

int main()
{
    hpx::future<int> f = hpx::async(&test);
    std::cout << f.get() << std::endl;
}
