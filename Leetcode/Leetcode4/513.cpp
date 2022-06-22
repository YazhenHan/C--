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
    int bfs(vector<TreeNode*> v) {
        vector<TreeNode*> vt;
        for (auto i : v) {
            if (i->left != nullptr) vt.push_back(i->left);
            if (i->right != nullptr) vt.push_back(i->right);
        }
        if (vt.empty()) return v.front()->val;
        else return bfs(vt);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        return bfs({root});
    }
};