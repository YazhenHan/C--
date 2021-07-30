#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size();
        int flag = 0;
        int temp = nums[0];
        int k = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == temp)
                k++;
            else
            {
                temp = nums[i];
                k = 0;
            }
            if (k > 1)
                flag++;
            nums[i - flag] = nums[i];
        }
        return nums.size() - flag;
    }
};