#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (auto & num : nums) {
            switch (num)
            {
            case 0:
                red++;
                break;
            case 1:
                white++;
                break;
            default:
                blue++;
                break;
            }
        }
        for (int i = 0; i < red; i++)
            nums[i] = 0;
        for (int i = red; i < red + white; i++)
            nums[i] = 1;
        for (int i = red + white; i < nums.size(); i++)
            nums[i] = 2;
    }
};