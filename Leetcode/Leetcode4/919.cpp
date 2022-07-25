// Definition for a binary tree node.
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

class CBTInserter {
private:
    TreeNode* root;
public:
    CBTInserter(TreeNode* root) : root(root) {

    }
    
    int insert(int val) {
        queue<TreeNode*> roots;
        roots.push(root);
        while (!roots.empty()) {
            TreeNode* temp = roots.front();
            if (temp->left) roots.push(temp->left);
            else {
                temp->left = new TreeNode(val);
                return temp->val;
            }
            if (temp->right) roots.push(temp->right);
            else {
                temp->right = new TreeNode(val);
                return temp->val;
            }
            roots.pop();
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return root;
    }
};
/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */