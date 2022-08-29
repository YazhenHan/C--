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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* head = nullptr, * ans = root, * temp = new TreeNode(val);
        while (root != nullptr && root->val > val) {
            head = root;
            root = root->right;
        }
        temp->left = root;
        if (head == nullptr)
            return temp;
        head->right = temp;
        return ans;
    }
};