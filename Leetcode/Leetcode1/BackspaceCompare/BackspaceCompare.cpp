#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        for (auto c : S) {
            if (c == '#')
            {
                if (!s.empty())
                {
                    s.pop();
                }
            } else {
                s.push(c);
            }
        }

        stack<char> t;
        for (auto c : T) {
            if (c == '#')
            {
                if (!t.empty())
                {
                    t.pop();
                }
            } else {
                t.push(c);
            }
        }

        if (s.size() != t.size())
        {
            return false;
        }
        

        while (!s.empty() && !t.empty())
        {
            if (s.top() != t.top())
            {
                return false;
            }
            s.pop();
            t.pop();
        }
        
        return true;
    }
};