#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root, int flag) {
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL && flag == 1)
        {
            return root->val;
        } else {
            return sumOfLeftLeaves(root->left, 1) + sumOfLeftLeaves(root->right, 0);
        }
    } else {
        return 0;
    }
}

int sumOfLeftLeaves(TreeNode* root) {
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return root->val;
        } else {
            return sumOfLeftLeaves(root->left, 1) + sumOfLeftLeaves(root->right, 0);
        }
    } else {
        return 0;
    }
}

int main() {
    return 0;
}