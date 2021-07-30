#include <iostream>
#include <vector>

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
    vector<int> res;
    void getT(TreeNode *root) {
        if (root == nullptr)
        {
            return;
        }
        getT(root->left);
        res.push_back(root->val);
        getT(root->right);
    }
public:
    bool findTarget(TreeNode *root, int k)
    {
        getT(root);
        int left = 0;
        int right = res.size() - 1;
        while (left < right)
        {
            int temp = res[left] + res[right];
            if(temp < k) {
                left++;
            } else if (temp == k) {
                return true;
            } else {
                right--;
            }
        }
        return false;
    }
};