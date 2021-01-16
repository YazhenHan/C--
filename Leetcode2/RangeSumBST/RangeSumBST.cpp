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
    vector<int> forAns;
    void center(TreeNode* root) {
        if (root == nullptr)
            return;
        center(root->left);
        forAns.push_back(root->val);
        center(root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        center(root);
        int ans = 0;
        for (auto a : forAns)
            if (a >= low && a <= high)
                ans += a;
        return ans;
    }
};