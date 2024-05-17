#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> indices(difficulty.size());
        for (size_t i = 0; i < indices.size(); i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&difficulty] (int i, int j) {
            return difficulty[i] <= difficulty[j];
        });
        vector<int> difficulty2;
        vector<int> profit2;
        for (int index : indices) {
            difficulty2.push_back(difficulty[index]);
            profit2.push_back(profit[index]);
        }

        int ans = 0;

        for (int work : worker) {
            int temp = 0;
            for (int i = 0; i < difficulty2.size() && difficulty2[i] <= work; i++) {
                temp = max(temp, profit2[i]);
            }
            ans += temp;
        }
        return ans;
    }
};