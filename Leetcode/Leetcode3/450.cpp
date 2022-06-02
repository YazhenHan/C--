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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->left == nullptr && root->right == nullptr) return nullptr;
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        TreeNode* temp = root->right;
        while (temp->left) temp = temp->left;
        root->right = deleteNode(root->right, temp->val);
        temp->right = root->right;
        temp->left = root->left;
        return temp;
    }
};