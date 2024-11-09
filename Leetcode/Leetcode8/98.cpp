#include <utility>

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
    bool ans = true;
    pair<long, long> dfs(TreeNode * root) {
        if (root == nullptr) return {LONG_MAX, LONG_MIN};
        pair<int64_t, int64_t> left, right;
        left = dfs(root->left);
        right = dfs(root->right);
        ans &= (left.second < root->val && root->val < right.first);
        return {min(min(min(left.first, right.first), (long)root->val), LONG_MAX), max(max(max(left.second, right.second), (long)root->val), LONG_MIN)};
    }
public:
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};