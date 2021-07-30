#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
        {
            return false;
        }
        
        int res = 1;
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                int tem = num / i;
                if (i == tem)
                {
                    res = res + i;
                } else {
                    res = res + i + tem;
                }
            }
        }
        if (res == num)
        {
            return true;
        }
        return false;
    }
};

int main() {
    int num;
    Solution sol;
    while (cin >> num)
    {
        cout << sol.checkPerfectNumber(num) << endl;
    }
    return 0;
}