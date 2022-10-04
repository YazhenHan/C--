#include <vector>


#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1, temp = 1;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] == nums[j - 1])
                continue;
            else if (nums[j] == nums[j - 1] + 1)
                temp++;
            else {
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};


#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = 1;
            if (!us.count(nums[i] - 1)) {
                while (us.count(nums[i] + 1)) {
                    temp++;
                    nums[i] = nums[i] + 1;
                }
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};