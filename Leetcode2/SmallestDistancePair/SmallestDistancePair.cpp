#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> forRes;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                forRes.push_back(nums[j] - nums[i]);
        sort(forRes.begin(), forRes.end());
        return forRes[k - 1];
    }
};