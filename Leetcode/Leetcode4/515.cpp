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
    void bfs(vector<TreeNode*> roots, vector<int>& ans) {
        vector<TreeNode*> vt;
        int min = INT32_MIN;
        for (auto root : roots) {
            min = max(root->val, min);
            if (root->left) vt.push_back(root->left);
            if (root->right) vt.push_back(root->right);
        }
        ans.push_back(min);
        if (vt.empty()) return;
        else bfs(vt, ans);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        bfs({root}, ans);
        return ans;
    }
};