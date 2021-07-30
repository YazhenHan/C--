#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> forRes;
        for (int i = 0; i < s.size(); i++)
        {
            string temp;
            while (i < s.size() && s[i] != ' ')
            {
                temp.push_back(s[i]);
                i++;
            }
            forRes.push_back(temp);
        }
        if (pattern.size() != forRes.size())
        {
            return false;
        }
        
        map<char, string> res;
        map<string, char> ser;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (res.find(pattern[i]) == res.end() && ser.find(forRes[i]) == ser.end())
            {
                res.insert({pattern[i], forRes[i]});
                ser.insert({forRes[i], pattern[i]});
            }
            else if (res[pattern[i]] != forRes[i] || ser[forRes[i]] != pattern[i])
                return false;
        }
        return true;
    }
};