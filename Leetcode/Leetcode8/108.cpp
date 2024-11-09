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
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        TreeNode * ans = new TreeNode(nums[(left + right) / 2]);
        ans->left = sortedArrayToBST(nums, left, (left + right) / 2 - 1);
        ans->right = sortedArrayToBST(nums, (left + right) / 2 + 1, right);
        return ans;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};