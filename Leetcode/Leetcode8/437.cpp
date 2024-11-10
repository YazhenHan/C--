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
    unordered_map<long long, int> prefix;
    int dfs(TreeNode * root, long long curr, int target) {
        if (!root) return 0;
        int ans = 0;
        curr += root->val;
        if (prefix.count(curr - target)) ans += prefix[curr - target];
        prefix[curr]++;
        ans += dfs(root->left, curr, target);
        ans += dfs(root->right, curr, target);
        prefix[curr]--;
        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};