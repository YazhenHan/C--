#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int AA = 0, BB = 0;
        unordered_set<int> uset;
        for (auto a : A)
            AA += a;
        for (auto b : B)
        {
            uset.insert(b);
            BB += b;
        }
        int cha = (BB - AA) / 2;
        for (auto a : A)
            if (uset.find(a + cha) != uset.end())
                return {a, a + cha};
        return {};
    }
};