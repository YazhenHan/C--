#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        vector<int> ans(ratings.size(), 0);
        if (ratings[0] <= ratings[1]) ans[0] = 1;
        if (ratings[ratings.size() - 1] <= ratings[ratings.size() - 2]) ans[ans.size() - 1] = 1;
        for (int i = 1; i < ratings.size() - 1; i++)
            if (ratings[i] <= ratings[i + 1] && ratings[i] <= ratings[i - 1])
                ans[i] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                ans[i] = ans[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                ans[i] = max(ans[i], ans[i + 1] + 1);
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};