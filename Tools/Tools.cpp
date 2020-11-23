#include "Tools.h"
#include <cmath>

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