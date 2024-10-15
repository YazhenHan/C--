class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int length1 = 1, length2 = 1;
        int temp1 = red, temp2 = blue;
        while (length1 % 2 != 0 && temp1 >= length1 || length1 % 2 == 0 && temp2 >= length1) {
            if (length1 % 2 != 0)
                temp1 -= length1;
            else
                temp2 -= length1;
            length1++;
        }
        temp1 = red, temp2 = blue;
        while (length2 % 2 != 0 && temp2 >= length2 || length2 % 2 == 0 && temp1 >= length2) {
            if (length2 % 2 != 0)
                temp2 -= length2;
            else
                temp1 -= length2;
            length2++;
        }
        return max(length1 - 1, length2 - 1);
    }
};