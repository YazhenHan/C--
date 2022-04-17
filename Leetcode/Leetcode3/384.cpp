#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
private:
    vector<int> original, shuff;
public:
    Solution(vector<int>& nums) {
        srand(time(0));
        for (int i = 0; i < nums.size(); i++) {
            original.push_back(nums[i]);
            shuff.push_back(nums[i]);
        }
    }
    
    vector<int> reset() {
        return shuff;
    }
    
    vector<int> shuffle() {
        vector<int> ans;
        for (int i = 0; i < original.size(); i++) {
            int t = rand() % (original.size() - i);
            ans.push_back(original[t]);
            original[t] = original[original.size() - i - 1];
        }
        original = shuff;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */