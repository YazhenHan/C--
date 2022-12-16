#include <vector>

using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        double sum = 0;
        for (auto num : nums)
            sum += num;
        return ceil(abs(sum - goal) / (double)limit);
    }
};