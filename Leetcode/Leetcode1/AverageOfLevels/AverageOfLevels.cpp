#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        queue<TreeNode *> q;
        if (root == nullptr)
        {
            return res;
        }
        q.push(root);
        while (!q.empty())
        {
            double sum = 0;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode* temp = q.front();
                sum += temp->val;
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
                q.pop();
            }
            res.push_back(sum / s);
        }
        return res;
    }
};
