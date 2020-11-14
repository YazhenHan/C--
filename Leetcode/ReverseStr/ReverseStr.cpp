#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        if (k >= s.size())
        {
            reverse(s.begin(), s.end());
            return s;
        }
        auto b = s.begin();
        auto e = b + k;
        while (e < s.end())
        {
            reverse(b, e);
            b = e + k;
            e = b + k;
        }
        reverse(b, s.end());
        return s;
    }
};

int main() {
    string s;
    int k;
    while (cin >> s >> k)
    {
        cout << (new Solution)->reverseStr(s, k) << endl;
    }
    
    return 0;
}