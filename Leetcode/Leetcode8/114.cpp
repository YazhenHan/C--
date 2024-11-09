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
    TreeNode* ans = new TreeNode();
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode * temp = root->right;
        ans->right = root;
        ans = ans->right;
        flatten(root->left);
        flatten(temp);
        root->left = nullptr;
    }
};