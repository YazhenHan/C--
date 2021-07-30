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
    vector<int> forRes;
    void cen(TreeNode* root) {
        if (root == nullptr)
            return;
        cen(root->left);
        forRes.push_back(root->val);
        cen(root->right);
    }
    TreeNode* ans(int i) {
        if (i == forRes.size())
            return nullptr;
        TreeNode* temp = new TreeNode(forRes[i]);
        temp->right = ans(i + 1);
        return temp;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        cen(root);
        return ans(0);
    }
};