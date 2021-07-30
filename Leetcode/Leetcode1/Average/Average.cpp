#include <vector>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = INT32_MAX, maxSalary = INT32_MIN;
        double res = 0;
        for (auto s : salary)
        {
            res += s;
            minSalary = min(minSalary, s);
            maxSalary = max(maxSalary, s);
        }
        return (res - minSalary - maxSalary) / (salary.size() - 2);
    }
};