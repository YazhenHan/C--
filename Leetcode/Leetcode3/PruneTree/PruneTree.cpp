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
    bool rec(TreeNode* root) {
        if (root == nullptr) return true;
        bool flag_left = rec(root->left);
        bool flag_right = rec(root->right);
        if (flag_left) root->left = nullptr;
        if (flag_right) root->right = nullptr;
        return root->val == 0 && flag_left && flag_right;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (rec(root)) return nullptr;
        return root;
    }
};