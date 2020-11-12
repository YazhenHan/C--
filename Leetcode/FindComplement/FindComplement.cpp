#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        vector<int> bin;
        while (num != 0)
        {
            int temp = num % 2;
            num = num / 2;
            bin.push_back(temp);
        }
        reverse(bin.begin(),bin.end());
        for(auto &b : bin) {
            if (b == 0)
            {
                b = 1;
            } else {
                b = 0;
            }
        }
        int temp = 1;
        int res = 0;
        for (int i = bin.size() - 1; i >= 0; i--)
        {
            res += bin[i] * temp;
            temp = temp * 2;
        }
        return res;
    }
};

int main() {
    int num;
    Solution sol;
    while (cin >> num)
    {
        cout << sol.findComplement(num) << endl;
    }
    return 0;
}