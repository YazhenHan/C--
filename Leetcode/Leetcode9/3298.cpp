#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> um1, um2;
        for (char c : word2) {
            um1[c]++;
            um2[c]++;
        }
        long long ans = 0ll;
        int left = 0, right = 0;
        while (right < word1.size()) {
            if (um1.count(word1[right])) {
                um1[word1[right]]--;
                if (um2.count(word1[right])) {
                    um2[word1[right]]--;
                    if (um2[word1[right]] == 0)
                        um2.erase(word1[right]);
                }
            }
            while (left < word1.size() && (um1.count(word1[left]) == 0 || um1[word1[left]] < 0)) {
                if (um1.count(word1[left]))
                    um1[word1[left]]++;
                left++;
            }
            if (um2.empty()) {
                ans += (left + 1);
            }
            right++;
        }
        return ans;
    }
};