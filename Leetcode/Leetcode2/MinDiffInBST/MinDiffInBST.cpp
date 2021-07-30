#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void getVector(TreeNode* root, vector<int>& forRes)
    {
        if (root == nullptr)
            return;
        getVector(root->left, forRes);
        forRes.push_back(root->val);
        getVector(root->right, forRes);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> res;
        getVector(root, res); 
        int ans = INT32_MAX;
        for (int i = 1; i < res.size(); i++)
            if (res[i] - res[i - 1] < ans)
                ans = res[i] - res[i - 1];
        return ans;
    }
};