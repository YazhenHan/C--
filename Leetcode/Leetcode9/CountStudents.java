package Leetcode.Leetcode9;

public class CountStudents {
    public int countStudents(int[] students, int[] sandwiches) {
        int top = 0, left = 0;
        while (top < sandwiches.length) {
            boolean flag = true;
            for (int i = 0; i < students.length; i++) {
                if (students[(left + i) % students.length] == sandwiches[top]) {
                    top++;
                    flag = false;
                    students[(left + i) % students.length] = -1;
                    break;
                }
            }
            if (flag) break;
        }
        int ans = 0;
        for (int student : students) {
            if (student != -1) ans++;
        }
        return ans;
    }
}
