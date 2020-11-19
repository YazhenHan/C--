#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for(int i = 0;i < nums.size();i++) {
            if (nums[i] != 0)
            {
                nums[cur] = nums[i];
                ++cur;
            }
        }
        for (int i = cur; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};

int main() {
    return 0;
}