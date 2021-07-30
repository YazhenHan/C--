#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left = 0,right = 0;
        bool flag = false;
        while (s[right] == ' ')
            right++;
        while (right < s.size())
        {
            if (s[right] != ' ')
            {
                s[left++] = s[right++];
                flag = false;
            }
            else
            {
                while (s[right] == ' ')
                    right++;
                s[left++] = ' ';
                flag = true;
            }
        }
        if (flag)
            left--;
        s.resize(left);
        
        auto b = s.begin();
        auto e = b;
        while (e != s.end())
        {
            if (*e == ' ')
            {
                reverse(b, e);
                b = e + 1;
                e = b;
            } else {
                ++e;
            }
        }
        reverse(b, e);
        reverse(s.begin(), s.end());
        return s;
    }
};