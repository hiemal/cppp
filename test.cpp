
#include <iostream>
#include "cppp.h"

using namespace cppp;

int primary(int num)
{
    std::cout << "This is #" + std::to_string(num) + " pig." << std::endl;
    for (auto i = 0; i < 1000000000; i++)
    {
    }
    return num;
}

void testprimary()
{
    std::cout << "testprimary" << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};
    auto pool = Pool(3);
    auto results = pool.map(primary, numbers);
    for (auto const &res : results)
        std::cout << res << ",";
    std::cout << std::endl;
}

struct Sth
{
    double a;
    std::vector<int> b;
};

bool dosth(std::vector<Sth> input)
{
    for (auto i = 0; i < 1000000000; i++)
    {
    }
    return true;
}

void teststl()
{
    std::cout << "teststl" << std::endl;
    std::vector<int> b;
    Sth x = {1.0, b};
    Sth y = {2.3, b};
    std::vector<Sth> input = {x, y};
    std::vector<std::vector<Sth>> inputs = {input, input};
    auto pool = Pool();
    auto results = pool.map(dosth, inputs);
    for (auto const &res : results)
        std::cout << res << ",";
    std::cout << std::endl;
}

int main()
{
    testprimary();
    teststl();
}