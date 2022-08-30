#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int cus = 0;
        for (int i = 0; i < popped.size(); i++) {
            while (s.empty() || s.top() != popped[i]) {
                if (cus == pushed.size()) return false;
                s.push(pushed[cus++]);
            }
            s.pop();
        }
        return true;
    }
};