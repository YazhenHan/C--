#include <unordered_set>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int temp = 1, ans = 1;
        unordered_set<int> us;
        while (true) {
            int t = temp % k;
            if (t == 0)
                return ans;
            if (us.count(t))
                return -1;
            us.insert(t);
            temp = t * 10 + 1;
            ans++;
        }
        return ans;
    }
};