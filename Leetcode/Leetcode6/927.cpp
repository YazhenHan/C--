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

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1)
                sum++;
        }
        if (sum % 3 != 0)
            return {-1, -1};
        if (sum == 0)
            return {0, 2};
        int first, second, third, cur = 0, partial = sum / 3;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                if (cur == 0)
                    first = i;
                else if (cur == partial)
                    second = i;
                else if (cur == partial * 2)
                    third = i;
                cur++;
            }
        }
        int len = arr.size() - third;
        if (first + len > second || second + len > third)
            return {-1, -1};
        for (int i = 0; i < len && first + i < second && second + i < third; i++) {
            if (arr[first + i] != arr[second + i] || arr[second + i] != arr[third + i])
                return {-1, -1};
        }
        return {first + len - 1, second + len};
    }
};