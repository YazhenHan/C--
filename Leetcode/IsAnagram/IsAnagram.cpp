#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int flag[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            flag[s[i] - 97]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            flag[t[i] - 97]--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (flag[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s, t;
    Solution sol;
    while (cin >> s >> t)
    {
        cout << sol.isAnagram(s, t) << endl;
    }
    return 0;
}