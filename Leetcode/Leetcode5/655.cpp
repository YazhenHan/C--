#include <vector>
#include <string>
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
    int getHeight(TreeNode* root) {
        if (root == nullptr) return -1;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        cout << height << " ";
        vector<vector<string>> ans(height + 1, vector<string>(pow(2, height + 1) - 1));
        ans[0][(pow(2, height + 1) - 1 - 1) / 2] = to_string(root->val);
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, (pow(2, height + 1) - 1 - 1) / 2});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (get<0>(t)->left) {
                ans[get<1>(t) + 1][get<2>(t) - pow(2, height - get<1>(t) - 1)] = to_string(get<0>(t)->left->val);
                q.push({get<0>(t)->left, get<1>(t) + 1, get<2>(t) - pow(2, height - get<1>(t) - 1)});
            }
            if (get<0>(t)->right) {
                ans[get<1>(t) + 1][get<2>(t) + pow(2, height - get<1>(t) - 1)] = to_string(get<0>(t)->right->val);
                q.push({get<0>(t)->right, get<1>(t) + 1, get<2>(t) + pow(2, height - get<1>(t) - 1)});
            }
        }
        return ans;
    }
};