#include <vector>

using namespace std;

struct TreeNode2 {
    int i, height;
    long fuel, mileage;
    vector<TreeNode2 *> childrens;
    TreeNode2(int i, int fuel, int height, int mileage) : i(i), fuel(fuel), height(height), mileage(mileage) {}
};

class Solution {
private:
    void buildTree(TreeNode2 * root, int target, vector<vector<int>>& stations, int& ans) {
        if (root->fuel + root->mileage >= target)
            ans = min(ans, root->height);
        for (int i = root->i; i < stations.size() && stations[i][0] <= root->fuel + root->mileage; i++)
            root->childrens.push_back(new TreeNode2(i + 1, root->fuel + stations[i][1] - (stations[i][0] - root->mileage), root->height + 1, stations[i][0]));
        for (auto& children : root->childrens)
            buildTree(children, target, stations, ans);
    }
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        TreeNode2 * root = new TreeNode2(0, startFuel, 0, 0);
        int ans = INT32_MAX;
        buildTree(root, target, stations, ans);
        return ans == INT32_MAX ? -1 : ans;
    }
};