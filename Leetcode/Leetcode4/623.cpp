#include <queue>

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
    void clear(queue<TreeNode*>& q) {
        queue<TreeNode*> empty;
        swap(empty, q);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        for (int level = 2; level < depth; level++) {
            auto temp = q;
            clear(q);
            while (!temp.empty()) {
                auto t = temp.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                temp.pop();
            }
        }

        while (!q.empty()) {
            auto t = q.front();
            TreeNode* left = new TreeNode(val);
            TreeNode* right = new TreeNode(val);
            left->left = t->left;
            right->right = t->right;
            t->left = left;
            t->right = right;
            q.pop();
        }

        return root;
    }
};