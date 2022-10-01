#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> um;
        int t = 0;
        for (auto c : s1) {
            um[c]++;
            if (um[c] == 1)
                t++;
        }
        for (int i = 0; i < s1.size(); i++) {
            um[s2[i]]--;
            if (um[s2[i]] == 0)
                t--;
            else if (um[s2[i]] == -1)
                t++;
        }
        if (t == 0) return true;
        for (int left = 0, right = s1.size(); right < s2.size(); left++, right++) {
            if (s2[left] == s2[right]) continue;
            um[s2[right]]--;
            um[s2[left]]++;
            if (um[s2[right]] == 0)
                t--;
            else if (um[s2[right]] == -1)
                t++;
            if (um[s2[left]] == 1)
                t++;
            else if (um[s2[left]] == 0)
                t--;
            if (t == 0)
                return true;
        }
        return false;
    }
};