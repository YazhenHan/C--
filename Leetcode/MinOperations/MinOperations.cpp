#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (auto log : logs) {
            if (log[0] == '.') {
                if (log[1] == '.')
                {
                    res = res > 0 ? res - 1: 0;
                }
            } else {
                res++;
            }
        }
        return res;
    }
};