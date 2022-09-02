#include <unordered_set>
#include <queue>

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
    int ans = 0;
    unordered_set<TreeNode*> us;
    int longestUnivaluePath2(TreeNode* root) {
        us.insert(root);
        if (root == nullptr) return 0;
        int temp1 = 0, temp2 = 0;
        if (root->left != nullptr && root->val == root->left->val)
            temp1 = longestUnivaluePath2(root->left) + 1;
        if (root->right != nullptr && root->val == root->right->val)
            temp2 = longestUnivaluePath2(root->right) + 1;
        ans = max(ans, max(temp1, temp2));
        if (temp1 != 0 && temp2 != 0)
            ans = max(ans, temp1 + temp2);
        return max(temp1, temp2);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            if (!us.count(t)) longestUnivaluePath2(t);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
            q.pop();
        }
        return ans;
    }
};