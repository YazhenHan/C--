struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int ans = INT32_MIN;
    int maxPath(TreeNode * root) {
        if (root == nullptr) return 0;
        int tl = max(maxPath(root->left), 0), tr = max(maxPath(root->right), 0);
        ans = max(tl + tr + root->val, ans);
        return max(tl, tr) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return ans;
    }
};