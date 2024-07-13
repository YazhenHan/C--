#include <vector>
#include <bitset>

using namespace std;

class Solution {
private:
    int countOnes(int number) {
        bitset<32> bits(number);
        return bits.count();
    }
public:
    bool canSortArray(vector<int>& nums) {
        bool flag1 = true, flag2 = true;
        int ma1 = INT32_MIN, ma2 = nums[0], mi2 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (countOnes(nums[i]) != countOnes(nums[i - 1])) {
                if (mi2 >= ma1) {
                    ma1 = ma2;
                    ma2 = nums[i];
                    mi2 = nums[i];
                } else {
                    flag2 = false;
                    break;
                }
            }
            ma2 = max(ma2, nums[i]);
            mi2 = min(mi2, nums[i]);
        }
        if (flag2 && mi2 >= ma1) {
            return true;
        } else {
            return false;
        }

    }
};