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
                if(aflag > 1) {
                    return false;
                }
                lflag = 0;
            } else if (c == 'L')
            {
                ++lflag;
                if(lflag > 2) {
                    return false;
                }
            } else {
                lflag = 0;
            }
        }
        return true;
    }
};