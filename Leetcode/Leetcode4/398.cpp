#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) : nums(nums) {
        srand(time(0));
    }
    
    int pick(int target) {
        int ans = 0, j = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (rand() % j == 0)
                    ans = i;
                j++;
            }
        }
        return ans;
    }
};

class Solution {
private:
    vector<int> nums;
    unordered_map<int, vector<int>> um;
public:
    Solution(vector<int>& nums) : nums(nums) {
        srand(time(0));
        for (int i = 0; i < nums.size(); i++)
            um[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        return um[target][rand() % um[target].size()];
    }
};