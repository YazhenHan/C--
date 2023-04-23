#include <vector>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 1000000);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int height = 0, width = 0;
            for (int j = i; j >= 0; j--) {
                if (width + books[j][0] <= shelfWidth) {
                    height = max(height, books[j][1]);
                    width += books[j][0];
                    dp[i + 1] = min(dp[i + 1], dp[j] + height);
                } else {
                    break;
                }
            }
        }
        return dp[n];
    }
};