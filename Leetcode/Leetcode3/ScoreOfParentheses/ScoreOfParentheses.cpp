#include <string>
#include <stack>

using namespace std;

struct Node
{
    int flag;
    int num;
};

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<Node> sn;
        for(int i = 0; i < s.size(); ++i) {
            Node temp;
            if ('(' == s[i]) {
                temp.flag = -1;
            } else {
                temp.flag = 0;
                if (-1 == sn.top().flag) {
                    temp.num = 1;
                    sn.pop();
                }
                else {
                    temp.num = 0;
                    while (0 == sn.top().flag) {
                        temp.num += sn.top().num;
                        sn.pop();
                    }
                    sn.pop();
                    temp.num *= 2;
                }
            }
            sn.push(temp);
        }
        int ans = 0;
        while (!sn.empty()) {
            ans += sn.top().num;
            sn.pop();
        }
        return ans;
    }
};