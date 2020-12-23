#include <vector>
#include <unordered_set>

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
    vector<TreeNode*> forRes;
    bool isRight(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        else if (root1 == nullptr || root2 == nullptr || root1->val != root2->val)
            return false;
        return isRight(root1->left, root2->left) && isRight(root1->right, root2->right);
    }
    void getTreeNodes(TreeNode* root) {
        if (root == nullptr)
            return;
        getTreeNodes(root->left);
        forRes.push_back(root);
        getTreeNodes(root->right);
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        getTreeNodes(root);
        vector<TreeNode*> res;
        unordered_set<int> set;
        for (int i = 0; i < forRes.size() && set.find(forRes[i]->val) == set.end(); i++)
            for (int j = 1; j < forRes.size(); j++)
                if (isRight(forRes[i], forRes[j]))
                {
                    res.push_back(forRes[i]);
                    set.insert(forRes[i]->val);
                    break;
                }
        return res;
    }
};