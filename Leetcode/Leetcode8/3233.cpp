#include <cmath>

using namespace std;

class Solution {
private:
    bool isPrime(int x) {
        if (x <= 1) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) 
                return false;
        }
        return true;
    }
public:
    int nonSpecialCount(int l, int r) {
        int ans = 0;
        for (int i = ceil(sqrt(l)); i * i <= r; i++) {
            if (isPrime(i)) 
                ans++;
        }
        return r - l + 1 - ans;
    }
};