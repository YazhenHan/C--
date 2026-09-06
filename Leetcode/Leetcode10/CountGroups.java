import java.util.ArrayList;
import java.util.List;

public class CountGroups {
    public int countGroups(int[] position, int[] speed, int distance) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i + 1 < position.length; i++) {
            if (position[i + 1] - position[i] > distance) {
                list.add(i);
            }
        }
        list.add(position.length - 1);

        int ans = 0;
        int temp = Integer.MAX_VALUE;
        for (int i = list.size() - 1; i >= 0; i--) {
            if (speed[list.get(i)] <= temp) ans++;
            temp = Math.min(temp, speed[list.get(i)]);
        }
        return ans;
    }
}
