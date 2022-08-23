#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_multiset<int> ums;
        for (auto t : target)
            ums.insert(t);
        for (auto t : arr)
            if (ums.find(t) == ums.end())
                return false;
            else
                ums.erase(ums.find(t));
        return true;
    }
};