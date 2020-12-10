#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string eva;
    cin >> eva;
    stack<char> op;
    stack<double> num;
    for (auto c : eva)
    {
        if (isdigit(c))
        {
            num.push(double(c - 48));
            if (op.empty())
            {
                continue;
            }
            if (op.top() == '*' || op.top() == '/')
            {
                char temp = op.top();
                op.pop();

                auto temp1 = num.top();
                num.pop();
                auto temp2 = num.top();
                num.pop();

                if (temp == '*')
                {
                    num.push(temp1 * temp2);
                }
                if (temp == '/')
                {
                    num.push(temp2 / temp1);
                }
            }
            
        } else {
            if (c == '+' || c == '-')
            {
                if (op.empty())
                {
                    op.push(c);
                    continue;
                }
                char temp = op.top();
                op.pop();
                op.push(c);

                auto temp1 = num.top();
                num.pop();
                auto temp2 = num.top();
                num.pop();
                
                if (temp == '+')
                {
                    num.push(temp1 + temp2);
                }
                if (temp == '-')
                {
                    num.push(temp2 - temp1);
                }
                
            } else if (c == '*' || c == '/')
            {
                op.push(c);
            }
        }
    }
    char temp = op.top();
    op.pop();

    auto temp1 = num.top();
    num.pop();
    auto temp2 = num.top();
    num.pop();
    
    if (temp == '+')
    {
        num.push(temp1 + temp2);
    }
    if (temp == '-')
    {
        num.push(temp2 - temp1);
    }
    cout << num.top();
    return 0;
}