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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (true) {
            queue<TreeNode*> t;
            while (!q.empty()) {
                if (q.front()->left) t.push(q.front()->left);
                if (q.front()->right) t.push(q.front()->right);
                ans += q.front()->val;
                q.pop();
            }
            if (t.empty())
                break;
            q = t;
            ans = 0;
        }
        return ans;
    }
};