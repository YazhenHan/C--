#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> umi;
    unordered_map<int, int> ump;
    TreeNode* buildTree(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr) {
        if (pl > pr) return nullptr;
        int t = postorder[pr];
        TreeNode* root = new TreeNode(t);
        int ti = umi[t];
        root->left = buildTree(inorder, il, ti - 1, postorder, pl, pl + (ti - il - 1));
        root->right = buildTree(inorder, ti + 1, ir, postorder, pl + (ti - il), pr - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            umi[inorder[i]] = i;
        for (int i = 0; i < postorder.size(); i++)
            ump[postorder[i]] = i;
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};