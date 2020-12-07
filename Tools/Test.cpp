#include "Tools.hpp"
#include <iostream>

int main()
{
    std::vector<std::vector<int>> a = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> b = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> x = {1, 2, 3};
    std::vector<int> y = {4, 5, 6};

    std::cout << Tools::dot(x, y) << std::endl << std::endl;

    std::vector<std::vector<int>> res;
    res = Tools::mult(a, b);
    Tools::outTVector(res);

    res = Tools::transpose(a);
    Tools::outTVector(res);

    std::vector<int> resres;
    resres = Tools::mult(a, x);
    Tools::outVector(resres);

    resres = Tools::mult(x, b);
    Tools::outVector(resres);

    return 0;
}