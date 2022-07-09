#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> us(arr.begin(), arr.end());
        int ans = 2;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int n1 = arr[i], n2 = arr[j], n3 = n1 + n2, temp = 2;
                while (us.count(n3)) {
                    n1 = n2;
                    n2 = n3;
                    n3 = n1 + n2;
                    temp++;
                }
                ans = max(ans, temp);
            }
        }
        return ans > 2 ? ans : 0;
    }
};