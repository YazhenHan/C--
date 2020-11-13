#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int mid = sqrt(area);
        int L = mid, W = mid;
        while (L * W != area)
        {
            if (L * W < area)
            {
                ++L;
            }
            else
            {
                --W;
            }
        }
        return vector<int>{L, W};
    }
};

int main()
{

    return 0;
}