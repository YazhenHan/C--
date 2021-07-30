#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    void tree2str(TreeNode *t, string &res)
    {
        int temp = t->val;
        if (temp < 0)
        {
            res.push_back('-');
            temp = -temp;
        }
        vector<int> temp2;
        while (temp != 0)
        {
            temp2.push_back(temp % 10);
            temp = temp / 10;
        }
        for(int i = temp2.size() - 1;i >= 0;i--)
        {
            res.push_back(temp2[i] + 48);
        }
        
        if (t->left != nullptr)
        {
            res.push_back('(');
            tree2str(t->left, res);
            res.push_back(')');
        }
        if (t->right != nullptr)
        {
            if (t->left == nullptr)
            {
                res.push_back('(');
                res.push_back(')');
            }
            res.push_back('(');
            tree2str(t->right, res);
            res.push_back(')');
        }
        
        
    }

public:
    string tree2str(TreeNode *t)
    {
        string res;
        if (t != nullptr)
        {
            tree2str(t, res);
        }
        return res;
    }
};