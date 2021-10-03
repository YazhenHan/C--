#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int left = 0, right = 0, flag = boxes[0] == '1' ? 1 : 0;
        int t = 0;
        for (int i = 1; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                right++;
                t += i - 0;
            }
        }
        ans.push_back(t);
        for (int i = 1; i < boxes.size(); i++) {
            left += flag;
            ans.push_back(ans.back() - right + left);
            flag = boxes[i] == '1' ? 1 : 0;
            right -= flag;
        }
        return ans;
    }
};