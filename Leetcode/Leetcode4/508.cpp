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
private:
    int TreeSum(TreeNode* root, unordered_map<int, int>& tsum) {
        if (root == nullptr) return 0;
        int sum = root->val + TreeSum(root->left, tsum) + TreeSum(root->right, tsum);
        if (tsum.count(sum)) tsum[sum] += 1;
        else tsum.insert({sum, 1});
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> tsum;
        TreeSum(root, tsum);
        int maxCount = 0;
        vector<int> ans;
        for (auto it = tsum.begin(); it != tsum.end(); it++) {
            if (it->second > maxCount) {
                ans.clear();
                ans.push_back(it->first);
                maxCount = it->second;
            } else if (it->second == maxCount) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};