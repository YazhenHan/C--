#include <iostream>
#include <vector>
#include <stdexcept>

namespace Tools
{
    // Vector dot product
    template <typename T>
    T dot(const std::vector<T>, const std::vector<T>);
    // Matrix multiplication
    template <typename T>
    std::vector<std::vector<T>> mult(const std::vector<std::vector<T>>, const std::vector<std::vector<T>>);
    // Matrix transpose
    template <typename T>
    std::vector<std::vector<T>> transpose(const std::vector<std::vector<T>>);
    // Matrix muptiplied by Vector
    template <typename T>
    std::vector<T> mult(const std::vector<std::vector<T>>, const std::vector<T>);
    // Vector multiplied by Matrix
    template <typename T>
    std::vector<T> mult(const std::vector<T>, const std::vector<std::vector<T>>);
} // namespace Tools

template <typename T>
T Tools::dot(const std::vector<T> x, const std::vector<T> y)
{
    if (x.size() == 0 || y.size() == 0 || x.size() != x.size())
    {
        throw std::runtime_error("the format of input is not correct!");
    }
    T res = 0;
    for (int i = 0; i < x.size(); i++)
    {
        res += x[i] * y[i];
    }
    return res;
}

template <typename T>
std::vector<std::vector<T>> Tools::mult(const std::vector<std::vector<T>> a, const std::vector<std::vector<T>> b)
{
    if (a.size() == 0 || a[0].size() == 0 || b.size() == 0 || b[0].size() == 0 || a[0].size() != b.size())
    {
        throw std::runtime_error("the format of input is not correct!");
    }
    std::vector<std::vector<T>> res;
    for (int i = 0; i < a.size(); i++)
    {
        std::vector<T> temp;
        for (int k = 0; k < b[i].size(); k++)
        {
            T tempInt = 0;
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

template <typename T>
std::vector<std::vector<T>> Tools::transpose(const std::vector<std::vector<T>> a)
{
    if (a.size() == 0 || a[0].size() == 0)
    {
        throw std::runtime_error("the format of input is not correct!");
    }

    std::vector<std::vector<T>> res;
    for (int i = 0; i < a[0].size(); i++)
    {
        std::vector<T> temp;
        for (int j = 0; j < a.size(); j++)
        {
            temp.push_back(a[j][i]);
        }
        res.push_back(temp);
    }
    return res;
}

template <typename T>
std::vector<T> Tools::mult(const std::vector<std::vector<T>> a, const std::vector<T> x)
{
    if (a.size() == 0 || a[0].size() == 0 || a[0].size() != x.size())
    {
        throw std::runtime_error("the format of input is not correct!");
    }
    std::vector<T> res;
    for (int i = 0; i < a.size(); i++)
    {
        T temp = 0;
        for (int j = 0; j < x.size(); j++)
        {
            temp += a[i][j] * x[j];
        }
        res.push_back(temp);
    }
    return res;
}

template <typename T>
std::vector<T> Tools::mult(const std::vector<T> y, const std::vector<std::vector<T>> a)
{
    if (a.size() == 0 || a[0].size() == 0 || a.size() != y.size())
    {
        throw std::runtime_error("the format of input is not correct!");
    }
    std::vector<T> res;
    for (int i = 0; i < a[0].size(); i++)
    {
        T temp = 0;
        for (int j = 0; j < y.size(); j++)
        {
            temp += y[j] * a[j][i];
        }
        res.push_back(temp);
    }
    return res;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> x)
{
    for (auto i : x)
    {
        os << i << " ";
    }
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> x)
{
    for (auto i : x)
    {
        os << i << std::endl;
    }
    return os;
}