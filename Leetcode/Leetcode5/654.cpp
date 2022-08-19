#include <vector>
#include <unordered_map>

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int max_v = INT32_MIN, max_i = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max_v) {
                max_v = nums[i];
                max_i = i;
            }
        }
        TreeNode* ans = new TreeNode(max_v);
        vector<int> temp_left(nums.begin(), nums.begin() + max_i);
        ans->left = constructMaximumBinaryTree(temp_left);
        vector<int> temp_right(nums.begin() + max_i + 1, nums.end());
        ans->right = constructMaximumBinaryTree(temp_right);
        return ans;
    }
};