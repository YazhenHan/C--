#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    struct VectorHash {
        size_t operator()(const std::vector<int>& vec) const {
            size_t hash = 0;
            for (int i : vec) {
                hash ^= std::hash<int>()(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2); // 结合哈希
            }
            return hash;
        }
    };

    struct VectorEqual {
        bool operator()(const std::vector<int>& lhs, const std::vector<int>& rhs) const {
            return lhs == rhs; // 使用 vector 的默认相等比较
        }
    };

    unordered_map<std::vector<int>, int, VectorHash, VectorEqual> um;

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (um.count(needs)) return um[needs];
        int ans = INT32_MAX;
        int temp = 0;
        for (int i = 0; i < needs.size(); i++) {
            temp += needs[i] * price[i];
        }
        ans = min(ans, temp);
        for (auto & s : special) {
            vector<int> temp;
            for (int i = 0; i < needs.size(); i++) {
                if (s[i] > needs[i]) {
                    break;
                } else {
                    temp.push_back(needs[i] - s[i]);
                }
            }
            if (temp.size() == needs.size())
                ans = min(ans, s.back() + shoppingOffers(price, special, temp));
        }
        um[needs] = ans;
        return ans;
    }
};