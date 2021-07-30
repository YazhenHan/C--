#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        deque<int> B;
        while (K != 0)
        {
            B.push_front(K % 10);
            K = K / 10;
        }
        deque<int> ans;
        int flag = 0;
        while (!A.empty() && !B.empty())
        {
            ans.push_front((A.back() + B.back() + flag) % 10);
            flag = (A.back() + B.back() + flag) / 10;
            A.pop_back();
            B.pop_back();
        }
        while (!A.empty())
        {
            ans.push_front((A.back() + flag) % 10);
            flag = (A.back() + flag) / 10;
            A.pop_back();
        }
        while (!B.empty())
        {
            ans.push_front((B.back() + flag) % 10);
            flag = (B.back() + flag) / 10;
            B.pop_back();
        }
        if (flag != 0)
            ans.push_front(flag);
        
        vector<int> an;
        while (!ans.empty())
        {
            an.push_back(ans.front());
            ans.pop_front();
        }
        return an;
    }
};