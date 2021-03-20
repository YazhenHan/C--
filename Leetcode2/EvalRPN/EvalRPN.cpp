#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    int sToI(string s) {
        int ans = 0, k = 0;
        if (s[0] == '-')
            k = 1;
        for (int i = k; i < s.size(); i++)
            ans = ans * 10 + (s[i] - '0');
        return s[0] == '-' ? -ans : ans;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& token : tokens)
        {
            if (token.size() > 1)
            {
                s.push(sToI(token));
                continue;
            }
            int num1, num2;
            switch (token[0])
            {
            case '+':
                num2 = s.top();
                s.pop();
                num1 = s.top();
                s.pop();
                s.push(num1 + num2);
                break;
            case '-':
                num2 = s.top();
                s.pop();
                num1 = s.top();
                s.pop();
                s.push(num1 - num2);
                break;
            case '*':
                num2 = s.top();
                s.pop();
                num1 = s.top();
                s.pop();
                s.push(num1 * num2);
                break;
            case '/':
                num2 = s.top();
                s.pop();
                num1 = s.top();
                s.pop();
                s.push(num1 / num2);
                break;
            default:
                s.push(sToI(token));
                break;
            }
        }
        return s.top();
    }
};