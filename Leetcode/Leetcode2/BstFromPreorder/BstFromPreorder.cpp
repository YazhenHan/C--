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
    void insertBST(TreeNode* root, int num) {
        if (num < root->val)
            if (root->left == nullptr)
                root->left = new TreeNode(num);
            else
                insertBST(root->left, num);
        else
            if (root->right == nullptr)
                root->right = new TreeNode(num);
            else
                insertBST(root->right, num);
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* ans = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
            insertBST(ans, preorder[i]);
        return ans;
    }
};