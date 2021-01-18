#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> us;
        for (auto a : A)
            if (us.find(a) == us.end())
                us.insert(a);
            else
                return a;
        return -1;
    }
};