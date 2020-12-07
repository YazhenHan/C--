#include "Tools.hpp"
#include <iostream>

int main()
{
    std::vector<std::vector<double>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> b = {{1, 2, 3}, {4, 5, 6}};

    std::vector<int> x = {1, 2, 3};
    std::vector<double> y = {4.5, 5.0};
    std::cout << Tools::mult(a, a) << std::endl;

    return 0;
}