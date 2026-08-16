package Leetcode.Leetcode10;

public class MinPenalty {
    public int minPenalty(int period, int[] lights, int[] arrivalTime) {
        int maxLight = 0;
        for (int light : lights) maxLight = Math.max(maxLight, light);
        int ans = 0;
        for (int at : arrivalTime) {
            if (at % period >= maxLight) {
                ans = Math.max(period - at % period, ans);
            }
        }
        return ans;
    }
}
