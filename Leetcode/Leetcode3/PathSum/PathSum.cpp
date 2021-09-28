#include <vector>

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
    void dfs(TreeNode* root, int targetSum, vector<int> t, vector<vector<int>>& ans) {
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                t.push_back(root->val);
                ans.push_back(t);
            }
        }
        else {
            t.push_back(root->val);
            if (root->left != nullptr)
                dfs(root->left, targetSum - root->val, t, ans);
            if (root->right != nullptr)
                dfs(root->right, targetSum - root->val, t, ans);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        vector<int> t;
        dfs(root, targetSum, t, ans);
        return ans;
    }
};