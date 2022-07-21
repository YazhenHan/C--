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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode * templeft = pruneTree(root->left);
        TreeNode * tempright = pruneTree(root->right);
        root->left = templeft;
        root->right = tempright;
        if (root->val == 0 && templeft == nullptr && root->right == nullptr)
                return nullptr;
        return root;
    }
};