#include <vector>
#include <unordered_map>

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
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int i, int j, int k, unordered_map<int, int>& um) {
        if (i >= preorder.size()) return nullptr;
        TreeNode* root = new TreeNode(preorder[i]);
        if (um[preorder[i]] > j)
            root->left = buildTree(preorder, inorder, i + 1, j, um[preorder[i]] - 1, um);
        if (um[preorder[i]] < k)
            root->right = buildTree(preorder, inorder, i + 1 + um[preorder[i]] - j, um[preorder[i]] + 1, k, um);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> um;
        for (int i = 0; i < inorder.size(); i++) um[inorder[i]] = i;
        return buildTree(preorder, inorder, 0, 0, inorder.size() - 1, um);
    }
};