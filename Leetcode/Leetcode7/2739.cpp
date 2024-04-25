class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        for (int i = 1; i <= mainTank; i++) {
            ans += 10;
            if (i % 5 == 0 && additionalTank >= 1) {
                mainTank++;
                additionalTank--;
            }
        }
        return ans;
    }
};