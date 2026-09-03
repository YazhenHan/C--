public class UniformArray {
    public boolean uniformArray(int[] nums1) {
        int minOdd = Integer.MAX_VALUE, minEven = Integer.MAX_VALUE;
        for (int num : nums1) {
            if (num % 2 == 0) {
                minEven = Math.min(num, minEven);
            } else {
                minOdd = Math.min(num, minOdd);
            }
        }
        return minOdd == Integer.MAX_VALUE || minEven == Integer.MAX_VALUE || minOdd < minEven;
    }
}
