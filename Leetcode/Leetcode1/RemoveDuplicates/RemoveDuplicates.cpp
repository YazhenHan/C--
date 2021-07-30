#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        for (auto c : S) {
            if (s.empty() || s.top() != c)
            {
                s.push(c);
            }
            else
            {
                s.pop();
            }
        }
        stack<char> ss;
        while (!s.empty())
        {
            ss.push(s.top());
            s.pop();
        }
        string res;
        while (!ss.empty())
        {
            res.push_back(ss.top());
            ss.pop();
        }
        return res;
    }
};