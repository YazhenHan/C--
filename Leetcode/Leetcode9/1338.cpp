#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> um;
        multiset<int> ms;
        for (int num : arr) {
            if (ms.find(um[num]) != ms.end())
                ms.erase(ms.find(um[num]));
            um[num]++;
            ms.insert(um[num]);
        }
        int ans = 0, temp = 0;
        for (multiset<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit) {
            temp += *rit;
            ans++;
            if (temp >= ceil(arr.size() / 2.0)) break;
        }
        return ans;
    }
};