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

class BSTIterator {
private:
    queue<int> forAns;
    void BSTIterator2(TreeNode* root) {
        if (root == nullptr)
            return;
        BSTIterator2(root->left);
        forAns.push(root->val);
        BSTIterator2(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        BSTIterator2(root);
    }
    
    int next() {
        int ans = forAns.front();
        forAns.pop();
        return ans;
    }
    
    bool hasNext() {
        return !forAns.empty();
    }
};
