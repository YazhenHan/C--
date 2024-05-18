#include <vector>

using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int fr = 0;
        vector<int> v(arr.size(), 0);
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[fr])
                fr = i;
            v[fr]++;
            if (v[fr] == k)
                return arr[fr];
        }
        return arr[fr];
    }
};