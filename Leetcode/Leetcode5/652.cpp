#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

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
    vector<TreeNode*> ans;
    bool findDuplicateSubtrees2(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 != nullptr) {
            findDuplicateSubtrees2(root1->left, root2);
            findDuplicateSubtrees2(root1->right, root2);
        }
        if (root2 != nullptr) {
            findDuplicateSubtrees2(root1, root2->left);
            findDuplicateSubtrees2(root1, root2->right);
        }
        bool temp1 = false, temp2 = false;
        if (root1 != nullptr && root2 != nullptr) {
            temp1 = findDuplicateSubtrees2(root1->left, root2->left);
            findDuplicateSubtrees2(root1->left, root2->right);
            findDuplicateSubtrees2(root1->right, root2->left);
            temp2 = findDuplicateSubtrees2(root1->right, root2->right);
            if (root1->val != root2->val) return false;
        }
        if (temp1 && temp2) { ans.push_back(root1); return true; }
        return false;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == nullptr) return ans;
        findDuplicateSubtrees(root->left);
        findDuplicateSubtrees(root->right);
        findDuplicateSubtrees2(root->left, root->right);
        return ans;
    }
};

class Solution {
private:
    unordered_map<string, TreeNode*> seen;
    unordered_set<TreeNode*> repeat;
public:
    string dfs(TreeNode* node) {
        if (node == nullptr) {
            return "";
        }
        string serial = to_string(node->val) + "(" + dfs(node->left) + ")(" + dfs(node->right) + ")";
        if (auto it = seen.find(serial); it != seen.end()) {
            repeat.insert(it->second);
        } else {
            seen[serial] = node;
        }
        return serial;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

    }
};