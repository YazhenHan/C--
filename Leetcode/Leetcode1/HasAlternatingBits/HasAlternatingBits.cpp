class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = n % 2;
        n = n / 2;
        while (n != 0)
        {
            int temp = n % 2;
            if (temp == flag)
            {
                return false;
            }
            flag = temp;
            n = n / 2;
        }
        return true;
    }
};