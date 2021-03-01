#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> num, num2;
public:
    NumArray(vector<int>& nums) {
        if (nums.size() == 0)
            return;
        num2 = nums;
        num.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            num.push_back(num.back() + nums[i]);
    }
    
    int sumRange(int i, int j) {
        return num[j] - num[i] + num2[i];
    }
};
