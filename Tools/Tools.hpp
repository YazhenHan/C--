#include <vector>

namespace Tools
{
    // Use Newton method to calculate square root
    double sqrtNew(double);

    // Output Vector
    void outVector(std::vector<int>);
    // Output Matrix
    void outTVector(std::vector<std::vector<int>>);

    // Vector dot product
    int dot(std::vector<int>, std::vector<int>);
    // Matrix multiplication
    std::vector<std::vector<int>> mult(std::vector<std::vector<int>>, std::vector<std::vector<int>>);
    // Matrix transpose
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>);
    // Matrix muptiplied by Vector
    std::vector<int> mult(std::vector<std::vector<int>>, std::vector<int>);
    // Vector multiplied by Matrix
    std::vector<int> mult(std::vector<int>, std::vector<std::vector<int>>);
} // namespace Tools