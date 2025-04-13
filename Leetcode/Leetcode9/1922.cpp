class Solution {
    public:
        int countGoodNumbers(long long n) {
            int mod = 1e9 + 7;
            long long even = 5, odd = 4;
    
            // 快速幂函数
            auto fastPow = [&](long long base, long long exp) -> long long {
                long long result = 1;
                while (exp > 0) {
                    if (exp % 2 == 1) {
                        result = (result * base) % mod;
                    }
                    base = (base * base) % mod;
                    exp /= 2;
                }
                return result;
            };
    
            long long evenCount = (n + 1) / 2; // 偶数位的数量
            long long oddCount = n / 2;       // 奇数位的数量
    
            // 分别计算偶数位和奇数位的贡献
            long long evenResult = fastPow(even, evenCount);
            long long oddResult = fastPow(odd, oddCount);
    
            return (evenResult * oddResult) % mod;
        }
    };