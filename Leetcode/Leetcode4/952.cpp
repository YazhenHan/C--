#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isRight(int num1, int num2) {
        for (int i = 2; i <= min(num1, num2); i++)
            if (num1 % i == 0 && num2 % i == 0)
                return true;
        return false;
    }

    void dfs(const vector<vector<int>> & edges, vector<bool> & filter, int j, int & ans) {
        if (filter[j]) return;
        filter[j] = true;
        ans++;
        for (auto i : edges[j])
            dfs(edges, filter, i, ans);
    }

    vector<int> id;
    vector<int> sz;
    int count;
    int find(int p) {
        if (p == id[p]) return p;
        return id[p] = find(id[p]);
    }
    void union2(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        count--;
    }
public:
    // dfs out of time
    int largestComponentSize(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> edges(N);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (isRight(nums[i], nums[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        vector<bool> filter(N, false);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (!filter[i]) {
                int temp = 0;
                dfs(edges, filter, i, temp);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
    
    // Union Find
    int largestComponentSize(vector<int>& nums) {
        int N = nums.size();
        vector<pair<int, int>> edges(N);
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (isRight(nums[i], nums[j]))
                    edges.push_back({i, j});

        id.resize(N);
        sz.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        count = N;
        for (auto edge : edges)
            union2(edge.first, edge.second);

        return *max_element(sz.begin(), sz.end());
    }
};