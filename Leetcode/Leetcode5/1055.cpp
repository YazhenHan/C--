#include <string>

using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int ans = 0;
        int i = 0;
        while (i < target.size()) {
            int j = 0;
            int t = i;
            while (j < source.size()) {
                if (source[j] == target[i])
                    i++;
                j++;
            }
            if (t == i) return -1;
            ans++;
        }
        return ans;
    }
};