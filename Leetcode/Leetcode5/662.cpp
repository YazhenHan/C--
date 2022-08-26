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
    struct NodePos
    {
        TreeNode* root;
        unsigned long pos;
        NodePos(TreeNode * root, unsigned long pos): root(root), pos(pos) {}
    };
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<NodePos> q;
        q.push({root, 1});
        unsigned long ans = 0;
        while (!q.empty()) {
            ans = max(ans, q.back().pos - q.front().pos + 1);
            queue<NodePos> t;
            while (!q.empty()) {
                if (q.front().root->left)
                    t.push({q.front().root->left, q.front().pos * 2 - 1});
                if (q.front().root->right)
                    t.push({q.front().root->right, q.front().pos * 2});
                q.pop();
            }
            q = t;
        }
        return ans;
    }
};