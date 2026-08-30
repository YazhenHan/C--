import java.math.BigInteger;

public class SumDecoded {
    private static final BigInteger MOD = BigInteger.valueOf(1_000_000_007L);
    
    public int sumDecoded(long[] nums) {
        BigInteger ans = BigInteger.ZERO;
        for (long num : nums) {
            int width = (int) (num % 10);
            String temp = String.valueOf(num / 10);
    
            BigInteger x = new BigInteger(temp.substring(0, width));
            BigInteger y = new BigInteger(temp.substring(width));
    
            BigInteger power = x.modPow(y, MOD);
            ans = ans.add(power).mod(MOD);
        }
        
        return ans.intValue();
    }
}
