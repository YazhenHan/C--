#include <vector>
#include <ctime>

using namespace std;

class Solution {
private:
    vector<vector<int>> rects;
    vector<int> nums;
    int len = 0;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for (auto&& rect : rects) {
            nums.push_back((rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
            len += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
        }
        srand(time(0));
    }
    
    vector<int> pick() {
        vector<int> ans;
        int r = rand() % len + 1;
        int i = 0, t = 0;
        while (t < r) {
            t += nums[i];
            i++;
        }
        i--;
        return {rand() % (rects[i][2] - rects[i][0] + 1) + rects[i][0], rand() % (rects[i][3] - rects[i][1] + 1) + rects[i][1]};
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */