#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'] = max(v[s[i] - 'a'], i);
        }
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            int temp = v[s[i] - 'a'], j = i;
            while (j < temp) {
                temp = max(temp, v[s[j] - 'a']);
                j++;
            }
            ans.push_back(j - i + 1);
            i = j;
        }
        return ans;
    }
};