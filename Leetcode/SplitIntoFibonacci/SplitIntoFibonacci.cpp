#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

class Solution
{
private:
    string splitStringLeft(string S, int right)
    {
        string res;
        for (int i = 0; i < right; i++)
        {
            res.push_back(S[i]);
        }
        return res;
    }
    string splitStringRight(string S, int right)
    {
        string res;
        for (int i = right; i < S.size(); i++)
        {
            res.push_back(S[i]);
        }
        return res;
    }
    long long sToInt(string s)
    {
        long long res = 0;
        long long temp = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            res += (s[i] - 48) * temp;
            temp *= 10;
        }
        return res;
    }
    bool splitIntoFibonacci(string S, vector<int> &res)
    {
        for (int i = 1; i <= S.size(); i++)
        {
            string left = splitStringLeft(S, i);
            if (left.size() > 1 && left[0] == '0')
            {
                return false;
            }
            if (sToInt(left) > INT32_MAX)
            {
                return false;
            }
            string right = splitStringRight(S, i);
            int i3 = (int)sToInt(left);
            if (res.size() < 2)
            {
                res.push_back(i3);
                if (!splitIntoFibonacci(right, res))
                {
                    res.pop_back();
                    if (res.size() < 2)
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return true;
                }
            }
            else
            {
                int i2 = res[res.size() - 1];
                int i1 = res[res.size() - 2];
                if (i1 < i3 - i2)
                {
                    return false;
                }
                else if (i1 == i3 - i2)
                {
                    res.push_back(i3);
                    if (i == S.size())
                    {
                        return true;
                    }
                    if (!splitIntoFibonacci(right, res))
                    {
                        res.pop_back();
                        if (res.size() < 2)
                        {
                            continue;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        return false;
    }

public:
    vector<int> splitIntoFibonacci(string S)
    {
        vector<int> res;
        splitIntoFibonacci(S, res);
        if (res.size() < 3)
        {
            res.resize(0);
        }
        return res;
    }
};

int main()
{
    string s = "5511816597";
    Solution sol;
    vector<int> res = sol.splitIntoFibonacci(s);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}