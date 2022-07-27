#include <string>
#include <stack>
#include <utility>

using namespace std;

class Solution {
private:
    pair<int, int> calculate(const pair<int, int> & expression1, const pair<int, int> & expression2) {
        return {expression1.first * expression2.second + expression2.first * expression1.second, 
                expression1.second * expression2.second};
    }
    pair<int, int> simplify(pair<int, int> expression) {
        for (int i = max(expression.first, expression.second); i >= 2; i--) {
            if (expression.first % i == 0 && expression.second % i == 0) {
                expression.first = expression.first / i;
                expression.second = expression.second / i;
                break;
            }
        }
        return expression;
    }
    
public:
    string fractionAddition(string expression) {
        stack<pair<int, int>> sp;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '/') {
                pair<int, int> temp;
                if (i - 3 >= 0 && expression[i - 3] == '+') {
                    temp.first = 10;
                } else if (i - 3 >= 0 && expression[i - 3] == '-') {
                    temp.first = -10;
                } else {
                    if (i - 2 >= 0 && !(expression[i - 2] == '+' || expression[i - 2] == '-')) {
                        temp.first = 10;
                    } else if (i - 2 >= 0 && expression[i - 2] == '+') {
                        temp.first = expression[i - 1] - '0';
                    } else if (i - 2 >= 0 && expression[i - 2] == '-') {
                        temp.first = (expression[i - 1] - '0') * -1;
                    } else {
                        temp.first = expression[i - 1] - '0';
                    }
                }
                if (i + 2 < expression.size() && !(expression[i + 2] == '+' || expression[i + 2] == '-')) {
                    temp.second = 10;
                } else {
                    temp.second = expression[i + 1] - '0';
                }
                sp.push(temp);
            }
        }
        while (sp.size() > 1) {
            auto temp1 = sp.top();
            sp.pop();
            auto temp2 = sp.top();
            sp.pop();
            sp.push(calculate(temp1, temp2));
        }
        auto ans = simplify(sp.top());
        return to_string(ans.first) + '/' + to_string(ans.second);
    }
};