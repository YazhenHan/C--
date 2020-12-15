#include <vector>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> res;
        while (N != 0)
        {
            res.push_back(N % 10);
            N = N / 10;
        }
        for (int i = res.size() - 1; i >= 1; i--)
        {
            int j = i - 1;
            while (j >= 0 && res[j] == res[i])
                j--;
            if (j >= 0 && res[j] < res[i])
            {
                res[i--]--;
                while (i >= 0)
                    res[i--] = 9;
                break;
            }
        }
        int r = 0;
        for (int i = res.size() - 1; i >= 0; i--)
            r = r * 10 + res[i];
        return r;
    }
};