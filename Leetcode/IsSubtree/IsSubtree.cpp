#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSubtree(TreeNode *s, TreeNode *t, TreeNode *th) {
        if (s == nullptr && t == nullptr)
        {
            return true;
        }
        if (s == nullptr && t != nullptr)
        {
            return false;
        }
        if (t == nullptr && s != nullptr)
        {
            return false;
        }
        if (s->val != t->val)
        {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
        else
        {
            return (isSubtree(s->left, t->left) && isSubtree(s->right, t->right))
            || isSubtree(s->left, th, th) || isSubtree(s->right, th, th);
        }
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        return isSubtree(s, t, t);
    }
};

int main()
{
    return 0;
}