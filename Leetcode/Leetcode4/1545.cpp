#include <string>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1 || k == 1) return '0';
        if (k == pow(2, n - 1)) return '1';
        else if (k > pow(2, n - 1)) return findKthBit(n - 1, pow(2, n - 1) - (k - pow(2, n - 1))) == '1' ? '0' : '1';
        else return findKthBit(n - 1, k);
    }
};