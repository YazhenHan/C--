#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class StringUnionFind {
private:
    std::unordered_map<std::string, std::string> parent; // 父节点映射
    std::unordered_map<std::string, int> rank;           // 秩映射

public:
    // 初始化集合
    void add(const std::string& s) {
        if (parent.find(s) == parent.end()) {
            parent[s] = s;
            rank[s] = 0;
        }
    }

    // 查找操作，带路径压缩
    std::string find(const std::string& s) {
        if (parent[s] != s) {
            parent[s] = find(parent[s]); // 路径压缩
        }
        return parent[s];
    }

    // 合并操作，按秩合并
    void unionSets(const std::string& s1, const std::string& s2) {
        std::string root1 = find(s1);
        std::string root2 = find(s2);
        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }

    // 判断两个字符串是否在同一个集合中
    bool connected(const std::string& s1, const std::string& s2) {
        return find(s1) == find(s2);
    }

    // 遍历所有集合
    std::unordered_map<std::string, std::vector<std::string>> getAllSets() {
        std::unordered_map<std::string, std::vector<std::string>> sets;
        for (const auto& entry : parent) {
            std::string root = find(entry.first); // 获取根节点
            sets[root].push_back(entry.first);    // 将元素加入对应根节点的集合中
        }
        return sets;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        StringUnionFind suf;
        unordered_map<string, string> um;
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                suf.add(account[i]);
                if (i - 1 > 0) suf.unionSets(account[i - 1], account[i]);
                um[account[i]] = account[0];
            }
        }

        vector<vector<string>> ans;
        for (auto& temp : suf.getAllSets()) {
            ans.emplace_back(vector<string>{um[temp.first]});
            ans[ans.size() - 1].insert(ans[ans.size() - 1].end(), temp.second.begin(), temp.second.end());
            sort(ans[ans.size() - 1].begin() + 1, ans[ans.size() - 1].end());
        }
        
        return ans;
    }
};