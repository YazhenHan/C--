struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool isUnivalTree(TreeNode* root, int val) {
        if (root == nullptr)
            return true;
        if (root->val != val)
            return false;
        return isUnivalTree(root->left, root->val) && isUnivalTree(root->right, root->val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isUnivalTree(root->left, root->val) && isUnivalTree(root->right, root->val);
    }
};