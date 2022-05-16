#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void order(TreeNode* root, vector<TreeNode*>& lv) {
        if (root->left != NULL)
            order(root->left, lv);
        lv.push_back(root);
        if (root->right != NULL)
            order(root->right, lv);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;
        vector<TreeNode*> lv;
        order(root, lv);
        for (int i = 0; i < lv.size() - 1; i++) {
            if (lv[i] == p)
                return lv[i + 1];
        }
        return NULL;
    }
};