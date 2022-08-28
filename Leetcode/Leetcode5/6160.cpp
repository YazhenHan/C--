#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            nums[i] = nums[i] + nums[i - 1];
        for (int i = 0; i < queries.size(); i++) {
            vector<int>::iterator t = lower_bound(nums.begin(), nums.end(), queries[i]);
            if(t == nums.end() || *t != queries[i])
                queries[i] = t - nums.begin();
            else
                queries[i] = t - nums.begin() + 1;
        }
        return queries;
    }
};