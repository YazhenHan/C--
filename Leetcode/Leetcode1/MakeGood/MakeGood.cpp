#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (auto c : s) {
            if (!st.empty())
            {
                auto temp = st.top();
                if(isupper(temp) && islower(c) && c == temp + 32) {
                    st.pop();
                    continue;
                }
                if(islower(temp) && isupper(c) && temp == c + 32) {
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        string res;
        while (!st.empty())
        {
            res.insert(res.begin(), st.top());
            st.pop();
        }
        return res;
    }
};