#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string res;
        if (num < 0)
        {
            res.push_back('-');
        }
        int num2 = abs(num);
        while (num2 != 0)
        {
            int temp = num2 % 7;
            res.push_back(temp + 48);
            num2 /= 7;
        }
        if (num < 0)
        {
            reverse(res.begin() + 1, res.end());
        } else {
            reverse(res.begin(), res.end());
        }
        return res;
    }
};

int main() {

}