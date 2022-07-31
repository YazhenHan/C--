#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        queue<pair<TreeNode*, int>> roots;
        roots.push({root, 1});
        int t = INT32_MIN, temp = 0, level = 1;
        while (!roots.empty()) {
            if (roots.front().second == level) {
                temp += roots.front().first->val;
            } else {
                if (temp > t) {
                    ans = level;
                    t = temp;
                }
                level++;
                temp = roots.front().first->val;
            }
            if (roots.front().first->left) roots.push({roots.front().first->left, level + 1});
            if (roots.front().first->right) roots.push({roots.front().first->right, level + 1});
            roots.pop();
        }
        if (temp > t) {
            ans = level;
            t = temp;
        }
        return ans;
    }
};