class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int ans = 0, temp = x;
        while (temp != 0) {
            ans += (temp % 10);
            temp /= 10;
        }
        return x % ans == 0 ? ans : -1;
    }
};