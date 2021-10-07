#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = 0, sum2 = 0;
        for (auto&& a : array1) sum1 += a;
        for (auto&& a : array2) sum2 += a;

        unordered_set<int> a2(array2.begin(), array2.end());

        vector<int> ans;
        if ((max(sum1, sum2) - min(sum1, sum2)) % 2 != 0) return ans;
        if (sum1 >= sum2) {
            int m = (sum1 - sum2) / 2;
            for (int i = 0; i < array1.size(); i++) {
                if (a2.find(array1[i] - m) != a2.end()) {
                    ans.push_back(array1[i]);
                    ans.push_back(array1[i] - m);
                    break;
                }
            }
        } else {
            int m = (sum2 - sum1) / 2;
            for (int i = 0; i < array1.size(); i++) {
                if (a2.find(array1[i] + m) != a2.end()) {
                    ans.push_back(array1[i]);
                    ans.push_back(array1[i] + m);
                    break;
                }
            }
        }
        return ans;
    }
};