#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        if (preorder.size() == 1) return new TreeNode(preorder.front());
        TreeNode* root = new TreeNode(preorder.front());
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder.front()) {
                vector<int> temp1(preorder.begin() + 1, preorder.begin() + 1 + i);
                vector<int> temp2(inorder.begin(), inorder.begin() + i);
                root->left = buildTree(temp1, temp2);
                vector<int> temp3(preorder.begin() + 1 + i, preorder.end());
                vector<int> temp4(inorder.begin() + 1 + i, inorder.end());
                root->right = buildTree(temp3, temp4);
                break;
            }
        }
        return root;
    }
};