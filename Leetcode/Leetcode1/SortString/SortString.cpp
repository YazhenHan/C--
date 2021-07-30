#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

class Solution
{
public:
    string sortString(string s)
    {
        string res;
        sort(s.begin(), s.end());
        list<char> l;
        for (int i = 0; i <= s.size(); i++)
        {
            l.push_back(s[i]);
        }
        while (!l.empty())
        {
            auto i = l.begin();
            char temp = *i;
            res.push_back(temp);
            l.erase(i);
            for (i = l.begin(); i != l.end();i++)
            {
                if (*i != temp)
                {
                    temp = *i;
                    res.push_back(temp);
                    auto k = i;
                    i--;
                    l.erase(k);
                }
            }
            if (l.empty())
            {
                break;
            }
            auto j = l.end();
            --j;
            temp = *j;
            res.push_back(temp);
            l.erase(j);
            if (l.empty())
            {
                break;
            }
            j = l.end();
            --j;
            for (; j != l.begin(); j--)
            {
                if (*j != temp)
                {
                    temp = *j;
                    res.push_back(temp);
                    auto k = j;
                    j++;
                    l.erase(k);
                }
            }
            if (*j != temp)
            {
                temp = *j;
                res.push_back(temp);
                auto k = j;
                j++;
                l.erase(k);
            }
        }
        return res;
    }
};

int main()
{
    string s;
    Solution sol;
    while (cin >> s)
    {
        cout << sol.sortString(s) << endl;
    }
    return 0;
}