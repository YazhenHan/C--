#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
private:
    static bool comp(string& str1, string& str2) {
        if (str1.size() == str2.size()) 
            return str1 > str2;
        return str1.size() > str2.size();
    }
    bool ss(string& str1, string& str2) {
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            if (str1[i] == str2[j])
                j++;
            i++;
        }
        return j == str2.size();
    }
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), comp);
        unordered_set<string> filter;
        for (int i = 0; i < strs.size() - 1; i++)
            if (strs[i] == strs[i + 1])
                filter.insert(strs[i]);
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (ss(strs[j], strs[i])) {
                    filter.insert(strs[i]);
                    break;
                }
            }
            if (!filter.count(strs[i]))
                return strs[i].size();
        }
        return -1;
    }
};