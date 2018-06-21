#include <iostream>
#include <hpx/hpx.hpp>


int test()
{
    return 42;
}

int run_test()
{
    hpx::future<int> f = hpx::async(&test);
    std::cout << f.get() << std::endl;
}

int ans = run_test();

int main()
{
    hpx::future<int> f = hpx::async(&test);
    std::cout << f.get() << std::endl;
}
