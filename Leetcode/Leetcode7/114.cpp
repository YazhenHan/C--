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
    vector<TreeNode*> v;
    void rfo(TreeNode* root) {
        if (root == nullptr) return;
        v.push_back(root);
        rfo(root->left);
        rfo(root->right);
    }
public:
    void flatten(TreeNode* root) {
        rfo(root);
        for (int i = 1; i < v.size(); i++) {
            root->right = v[i];
            root->left = nullptr;
            root = root->right;
        }
    }
};