#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int aflag = 0;
        int lflag = 0;
        for(auto c : s) {
            if (c == 'A')
            {
                ++aflag;
                lflag = 0;
            } else if (c == 'L')
            {
                ++lflag;
            } else {
                lflag = 0;
            }
        }
        if (aflag > 1 || lflag > 2)
        {
            return false;
        }
        return true;
    }
};