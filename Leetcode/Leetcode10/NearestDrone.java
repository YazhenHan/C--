package Leetcode.Leetcode10;

public class NearestDrone {
    public int nearestDrone(int[][] drones, int[] target) {
        int dis = Integer.MAX_VALUE;
        int ans = -1;
        for (int i = 0; i < drones.length; i++) {
            int currentDis = Math.abs(drones[i][0] - target[0]) + Math.abs(drones[i][1] - target[1]);
            if (currentDis <= drones[i][2] && currentDis < dis) {
                dis = currentDis;
                ans = i;
            }
        }
        return ans;
    }
}
