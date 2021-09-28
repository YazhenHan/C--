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
    void dfs(TreeNode* root, int targetSum, vector<int> t, int& ans) {
        t.push_back(root->val);
        int sum = 0;
        for (int i = t.size() - 1; i >= 0; i--) {
            sum += t[i];
            if (sum == targetSum)
                ans++;
        }
        if (root->left != nullptr)
            dfs(root->left, targetSum, t, ans);
        if (root->right != nullptr)
            dfs(root->right, targetSum, t, ans);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        if (root != nullptr)
            dfs(root, targetSum, vector<int>(), ans);
        return ans;
    }
};