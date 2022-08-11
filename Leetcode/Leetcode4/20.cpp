#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for (auto c : s) {
            switch (c)
            {
            case '(':
                sc.push('(');
                break;
            case '[':
                sc.push('[');
                break;
            case '{':
                sc.push('{');
                break;
            case ')':
                if (sc.empty() || sc.top() != '(')
                    return false;
                sc.pop();
                break;
            case ']':
                if (sc.empty() || sc.top() != '[')
                    return false;
                sc.pop();
                break;
            case '}':
                if (sc.empty() || sc.top() != '{')
                    return false;
                sc.pop();
                break;
            }
        }
        return sc.empty();
    }
};