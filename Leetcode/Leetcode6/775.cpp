#include <vector>

using namespace std;

// Out of time.
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] > nums[i + 1])
                ans++;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--)
                if (nums[j] > nums[i])
                    ans--;
        }
        return ans == 0;
    }
};

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), temp = nums[n - 1];
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i] > temp)
                return false;
            temp = min(temp, nums[i + 1]);
        }
        return true;
    }
};