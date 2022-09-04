#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> v(26, -1);
        for (int i = 0; i < s.size(); i++) {
            if (v[s[i] - 'a'] == -1)
                v[s[i] - 'a'] = i;
            else {
                if (i - v[s[i] - 'a'] - 1 != distance[s[i] - 'a'])
                    return false;
            }
        }
        return true;
    }
};