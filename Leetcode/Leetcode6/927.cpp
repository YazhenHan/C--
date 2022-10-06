#include <vector>

using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        int left = arr[i], right = arr.back();
        int middle = 0;
        for (int k = i + 1; k < j; k++)
            middle = middle * 2 + arr[k];
        while (i < j) {
            if (left == middle && middle == right)
                break;
            if (middle < left || middle < right)
                return vector<int>(2, -1);
            if (left < right) {
                i++;
                left = left * 2 + arr[i];
                middle = middle - arr[i] * pow(2, (arr.size() - (i + 1) - (arr.size() - j)));
            } else {
                j--;
                right = arr[j] * pow(2, arr.size() - j - 1) + right;
                middle = middle / 2;
            }
        }
        return {i, j};
    }
};