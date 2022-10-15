#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int m = 1;
        for (auto t : target) {
            while (m < t) {
                ans.push_back("Push");
                ans.push_back("Pop");
                m++;
            }
            ans.push_back("Push");
            m++;
        }
        return ans;
    }
};