#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res;
        res.resize(s.size());
        for (int i = 0; i < s.size(); i++)
            res[indices[i]] = s[i];
        return res;
    }

    string restoreString(string s, vector<int>& indices) {
        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            char temp = s[j];
            char temp2 = s[indices[j]];
            while (i != indices[j])
            {
                s[indices[j]] = temp;
                j = indices[j];
                temp = temp2;
                temp2 = s[indices[j]];
            }
            s[indices[j]] = temp;
        }
        return s;
    }
};