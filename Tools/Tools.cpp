#include "Tools.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace Tools
{
    double sqrtNew(double c)
    {
        double err = 1e-15;
        double t = c;
        while (std::abs(t - c / t) > err * t)
        {
            t = (c / t + t) / 2.0;
        }
        return t;
    }

    void outVector(std::vector<int> x)
    {
        for (int i = 0; i < x.size(); i++)
        {
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void outTVector(std::vector<std::vector<int>> a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                std::cout << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    int dot(std::vector<int> x, std::vector<int> y)
    {
        if (x.size() == 0 || y.size() == 0 || x.size() != x.size())
        {
            throw std::runtime_error("the format of input is not correct!");
        }
        int res = 0;
        for (int i = 0; i < x.size(); i++)
        {
            res += x[i] * y[i];
        }
        return res;
    }

    std::vector<std::vector<int>> mult(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b)
    {
        if (a.size() == 0 || a[0].size() == 0 || b.size() == 0 || b[0].size() == 0 || a[0].size() != b.size())
        {
            throw std::runtime_error("the format of input is not correct!");
        }
        std::vector<std::vector<int>> res;
        for (int i = 0; i < a.size(); i++)
        {
            std::vector<int> temp;
            for (int k = 0; k < b[i].size(); k++)
            {
                int tempInt = 0;
                for (int j = 0; j < b.size(); j++)
                {
                    tempInt += a[i][j] * b[j][k];
                }
                temp.push_back(tempInt);
            }
            res.push_back(temp);
        }
        return res;
    }

    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> a)
    {
        if (a.size() == 0 || a[0].size() == 0)
        {
            throw std::runtime_error("the format of input is not correct!");
        }

        std::vector<std::vector<int>> res;
        for (int i = 0; i < a[0].size(); i++)
        {
            std::vector<int> temp;
            for (int j = 0; j < a.size(); j++)
            {
                temp.push_back(a[j][i]);
            }
            res.push_back(temp);
        }
        return res;
    }

    std::vector<int> mult(std::vector<std::vector<int>> a, std::vector<int> x)
    {
        if (a.size() == 0 || a[0].size() == 0 || a[0].size() != x.size())
        {
            throw std::runtime_error("the format of input is not correct!");
        }
        std::vector<int> res;
        for (int i = 0; i < a.size(); i++)
        {
            int temp = 0;
            for (int j = 0; j < x.size(); j++)
            {
                temp += a[i][j] * x[j];
            }
            res.push_back(temp);
        }
        return res;
    }

    std::vector<int> mult(std::vector<int> y, std::vector<std::vector<int>> a)
    {
        if (a.size() == 0 || a[0].size() == 0 || a[0].size() != y.size())
        {
            throw std::runtime_error("the format of input is not correct!");
        }
        std::vector<int> res;
        for (int i = 0; i < a[0].size(); i++)
        {
            int temp = 0;
            for (int j = 0; j < y.size(); j++)
            {
                temp += y[j] * a[j][i];
            }
            res.push_back(temp);
        }
        return res;
    }
} // namespace Tools