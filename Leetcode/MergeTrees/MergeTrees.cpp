#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr && t2 == nullptr)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(0);
        if (t1 != nullptr && t2 != nullptr)
        {
            root->val = t1->val + t2->val;
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
        }
        else if (t1 != nullptr)
        {
            root->val = t1->val;
            root->left = mergeTrees(t1->left, t2);
            root->right = mergeTrees(t1->right, t2);
        }
        else if (t2 != nullptr)
        {
            root->val = t2->val;
            root->left = mergeTrees(t1, t2->left);
            root->right = mergeTrees(t1, t2->right);
        }
        return root;
    }
};
