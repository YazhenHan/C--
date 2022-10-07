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
    TreeNode* expandBinaryTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->left != nullptr) {
            TreeNode * temp = new TreeNode(-1);
            temp->left = root->left;
            root->left = temp;
            expandBinaryTree(temp->left);
        }
        if (root->right != nullptr) {
            TreeNode * temp = new TreeNode(-1);
            temp->right = root->right;
            root->right = temp;
            expandBinaryTree(temp->right);
        }
        return root;
    }
};