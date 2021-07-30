#include <vector>
#include<algorithm>

using namespace std;

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
private:
    void findSecondMinimumValue(TreeNode *root, vector<int> &forRes)
    {
        if (root == nullptr)
        {
            return;
        }
        forRes.push_back(root->val);
        findSecondMinimumValue(root->left, forRes);
        findSecondMinimumValue(root->right, forRes);
    }

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        vector<int> forRes;
        findSecondMinimumValue(root, forRes);
        sort(forRes.begin(),forRes.end());
        for (int i = 1; i < forRes.size(); i++)
        {
            if (forRes[i] != forRes[i-1])
            {
                return forRes[i];
            }
        }
        return -1;
    }
};