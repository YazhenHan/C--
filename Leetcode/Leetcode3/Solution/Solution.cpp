#include <vector>
#include <ctime>

using namespace std;


class Solution {
public:
    Solution(vector<int>& w) {
        float v_sum = 0.0f;
        for (auto& t : w) v_sum += t;
        v.push_back(0.0);
        for (auto& t : w) v.push_back(v.back() + t / v_sum);
        srand(time(NULL));
    }
    
    int pickIndex() {
        float r = rand() * 1.0f / RAND_MAX;
        return searchRight(r);
    }
private:
    vector<float> v;
    int searchRight(float f) {
        int left = 1, right = v.size() - 1;
        while (left <= right) {
            int temp = (left + right) / 2;
            if (v[temp] >= f && v[temp - 1] <= f) return temp - 1;
            else if (v[temp] < f) left++;
            else right--;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */