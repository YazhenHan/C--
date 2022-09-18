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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> roots, temps;
        roots.push_back(root);
        bool flag = false;
        while (!roots.empty()) {
            temps.clear();
            for (int i = 0; i < roots.size(); i++) {
                if (roots[i]->left)
                    temps.push_back(roots[i]->left);
                if (roots[i]->right)
                    temps.push_back(roots[i]->right);
            }
            if (flag) {
                int j = 0, k = roots.size() - 1;
                while (j < k) {
                    swap(roots[j]->val, roots[k]->val);
                    j++;
                    k--;
                }
            }
            roots = temps;
            flag = !flag;
        }
        return root;
    }
};