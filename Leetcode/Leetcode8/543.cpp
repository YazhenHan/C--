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
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)), depth(root->left) + depth(root->right));
    }
};

class Solution {
private:
    int ans = 0;
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = depth(root->left), right = depth(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        depth(root);
        return ans;
    }
};