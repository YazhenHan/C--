class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if ((a - e) * (d - f) == (c - e) * (b - f)) {
            if (a == c && c == e || b == d && d == f) {
                if (c > min(a, e) && c < max(a, e) || d > min(b, f) && d < max(b, f)) {
                    return 2;
                } else {
                    return 1;
                }
            } else {
                if (a > min(c, e) && a < max(c, e)) {
                    return 2;
                } else {
                    return 1;
                }
            }
        } else {
            if (a == e || b == f || abs(c - e) == abs(d - f)) {
                return 1;
            } else {
                return 2;
            }
        }
    }
};