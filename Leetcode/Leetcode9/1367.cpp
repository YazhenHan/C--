struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool isSubPath(ListNode* head, TreeNode* root, ListNode* head2, TreeNode* root2) {
        if (head == nullptr) return true;
        if (root == nullptr) return false;
        if (root->val == head->val) {
            return isSubPath(head->next, root->left, head2, root2) || isSubPath(head->next, root->right, head2, root2);
        } else {
            return isSubPath(head2, root2->left, head2, root2->left) || isSubPath(head2, root2->right, head2, root2->right);
        }
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return isSubPath(head, root, head, root);
    }
};

class Solution {
private:
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;
        if (root == nullptr || root->val != head->val) return false;
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};