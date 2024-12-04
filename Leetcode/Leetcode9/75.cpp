#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (int num : nums) {
            switch (num) {
                case 0: red++; break;
                case 1: white++; break;
                case 2: blue++; break;
            }
        }

        int i = 0;
        while (red > 0) {
            nums[i] = 0;
            i++;
            red--;
        }
        while (white > 0) {
            nums[i] = 1;
            i++;
            white--;
        }
        while (blue > 0) {
            nums[i] = 2;
            i++;
            blue--;
        }
    }
};