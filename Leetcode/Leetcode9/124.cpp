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
    unordered_map<TreeNode*, int> um;
    int maxPath(TreeNode* root) {
        if (root == nullptr) return INT32_MIN;
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        int ans = max(max(left, right), 0) + root->val;
        um[root] = ans;
        return ans;
    }
    int dfs(TreeNode* root) {
        if (root == nullptr) return INT32_MIN;
        return max(max(dfs(root->left), dfs(root->right)), max(um[root->left], 0) + max(um[root->right], 0) + root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        um[nullptr] = INT32_MIN;
        maxPath(root);
        return dfs(root);
    }
};