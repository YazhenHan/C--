#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string smallest = s;
            for (int i = 0; i < s.size(); i++) {
                char c = s[0];
                s = s.substr(1);
                s.push_back(c);
                if (s < smallest)
                    smallest = s;
            }
            return smallest;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};