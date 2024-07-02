#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        unordered_set<int> us = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        while (!us.count(nums[left])) left++;
        while (!us.count(nums[right])) right--;
        return right - left;
    }
};