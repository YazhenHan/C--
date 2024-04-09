class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        return (weeks * (2 * 28 + (weeks - 1) * 7) / 2) + (days * (2 * (weeks + 1) + (days - 1) * 1) / 2);
    }
};