#include <algorithm>

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
    int getlength(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(getlength(root->left) + 1, getlength(root->right) + 1);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (getlength(root->left) == getlength(root->right)) {
            return root;
        }
        else if (getlength(root->left) > getlength(root->right)) {
            return subtreeWithAllDeepest(root->left);
        }
        else {
            return subtreeWithAllDeepest(root->right);
        }
    }
};