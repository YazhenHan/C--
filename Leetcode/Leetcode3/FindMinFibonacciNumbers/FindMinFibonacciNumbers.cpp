#include <vector>

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibonacci(2, 1);
        int t1 = 1, t2 = 1, t = t1 + t2;
        while (t <= k) {
            fibonacci.push_back(t);
            t1 = t2;
            t2 = t;
            t = t1 + t2;
        }
        int ans = 0;
        for (int i = fibonacci.size() - 1; k != 0; i--) {
            if (fibonacci[i] > k) continue;
            k -= fibonacci[i];
            ans++;
        }
        return ans;
    }
};