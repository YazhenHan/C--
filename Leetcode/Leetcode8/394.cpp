#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<int> si;
        stack<string> ss;
        int cur = 0;
        while (cur < s.size()) {
            if (isdigit(s[cur])) {
                int temp = 0;
                while (cur != s.size() && isdigit(s[cur])) {
                    temp = temp * 10 + s[cur] - '0';
                    cur++;
                }
                si.push(temp);
                cur--;
            } else {
                if (s[cur] == ']') {
                    stack<string> temp;
                    while (ss.top() != "[") {
                        temp.push(ss.top());
                        ss.pop();
                    }
                    ss.pop();
                    string str;
                    while (!temp.empty()) {
                        str.append(temp.top());
                        temp.pop();
                    }
                    int in = si.top();
                    si.pop();
                    string ans;
                    while (in--) {
                        ans.append(str);
                    }
                    ss.push(ans);
                } else {
                    ss.push(string(1, s[cur]));
                }
            }

            cur++;
        }
        stack<string> temp;
        while (!ss.empty()) {
            temp.push(ss.top());
            ss.pop();
        }
        string str;
        while (!temp.empty()) {
            str.append(temp.top());
            temp.pop();
        }
        return str;
    }
};