#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> um;
        for (char c : p) um[c]++;
        auto temp = um;
        int left = 0, right = 0;
        vector<int> ans;
        while (right < s.size()) {
            if (temp.count(s[right])) {
                temp[s[right]]--;
                if (temp[s[right]] == 0) temp.erase(s[right]);
                if (temp.empty()) {
                    ans.push_back(left);
                    temp[s[left]]++;
                    left++;
                }
            } else {
                while (s[left] != s[right]) {
                    temp[s[left]]++;
                    left++;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};