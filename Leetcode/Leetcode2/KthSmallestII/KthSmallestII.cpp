struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallestII(TreeNode* root, TreeNode* nodenum_root, int k) {
        int left = nodenum_root->left == nullptr ? 0 : nodenum_root->left->val;
        if (left + 1 == k)
            return root->val;
        else if (left + 1 > k)
            return kthSmallestII(root->left, nodenum_root->left, k);
        else
            return kthSmallestII(root->right, nodenum_root->right, k - left - 1);
    }
};