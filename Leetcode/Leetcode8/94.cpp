#include <vector>
#include <algorithm>
#include <iterator>

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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        vector<int> temp1 = inorderTraversal(root->left);
        copy(temp1.begin(), temp1.end(), back_inserter(ans));
        ans.push_back(root->val);
        vector<int> temp2 = inorderTraversal(root->right);
        copy(temp2.begin(), temp2.end(), back_inserter(ans));
        return ans;
    }
};