#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
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
        return s;
    }
};