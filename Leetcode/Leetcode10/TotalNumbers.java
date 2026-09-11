import java.util.HashSet;
import java.util.Set;

public class TotalNumbers {
    public int totalNumbers(int[] digits) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < digits.length; i++) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < digits.length; j++) {
                if (j == i) continue;
                for (int k = 0; k < digits.length; k++) {
                    if (k == i || k == j || digits[k] % 2 != 0) continue;
                    int temp = digits[i] * 100 + digits[j] * 10 + digits[k];
                    set.add(temp);
                }
            }
        }
        return set.size();
    }
}
