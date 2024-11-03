#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0;
        for (int i = citations.size() - 1; i >= 0; i--) {
            if (citations[i] >= ans + 1) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};