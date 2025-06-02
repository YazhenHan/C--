#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int size = ratings.size();
        vector<int> v(size, 1);
        for (int i = 1; i < size; i++) {
            v[i] = ratings[i] > ratings[i - 1] ? v[i - 1] + 1 : 1;
        }
        for (int i = size - 2; i >= 0; i--) {
            v[i] = max(v[i], ratings[i] > ratings[i + 1] ? v[i + 1] + 1 : 1);
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};