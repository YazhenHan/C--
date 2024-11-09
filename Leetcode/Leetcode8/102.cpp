#include <vector>
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> temp = q;
            while (!q.empty()) q.pop();
            vector<int> v;
            while (!temp.empty()) {
                v.push_back(temp.front()->val);
                if (temp.front()->left) q.push(temp.front()->left);
                if (temp.front()->right) q.push(temp.front()->right);
                temp.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
};