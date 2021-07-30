#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> forRes;
        for (string &s : ops)
        {
            int temp1, temp2;
            switch (s[0])
            {
            case '+':
                temp1 = forRes.top();
                forRes.pop();
                temp2 = forRes.top();
                forRes.push(temp1);
                forRes.push(temp1 + temp2);
                break;
            case 'D':
                forRes.push(forRes.top() * 2);
                break;
            case 'C':
                forRes.pop();
                break;
            default:
                forRes.push(stoi(s));
                break;
            }
        }
        int res = 0;
        while (!forRes.empty())
        {
            res += forRes.top();
            forRes.pop();
        }
        return res;
    }
};