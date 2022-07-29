#include <vector>

using namespace std;

class Solution {
private:
    bool isVertical(const vector<int>& l1, const vector<int>& l2) {
        return l1[0] * l2[0] + l1[1] * l2[1] == 0 && l1[0] * l1[0] + l1[1] * l1[1] == l2[0] * l2[0] + l2[1] * l2[1];
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1 == p2 && p2 == p3 && p3 == p4) return false;
        return isVertical({p2[0] - p1[0], p2[1] - p1[1]}, {p4[0] - p3[0], p4[1] - p3[1]}) &&
               isVertical({p3[0] - p1[0], p3[1] - p1[1]}, {p4[0] - p1[0], p4[1] - p1[1]}) &&
               isVertical({p3[0] - p2[0], p3[1] - p2[1]}, {p4[0] - p2[0], p4[1] - p2[1]})
               ||
               isVertical({p3[0] - p1[0], p3[1] - p1[1]}, {p4[0] - p2[0], p4[1] - p2[1]}) &&
               isVertical({p2[0] - p1[0], p2[1] - p1[1]}, {p4[0] - p1[0], p4[1] - p1[1]}) &&
               isVertical({p2[0] - p3[0], p2[1] - p3[1]}, {p4[0] - p3[0], p4[1] - p3[1]})
               ||
               isVertical({p4[0] - p1[0], p4[1] - p1[1]}, {p3[0] - p2[0], p3[1] - p2[1]}) &&
               isVertical({p3[0] - p1[0], p3[1] - p1[1]}, {p2[0] - p1[0], p2[1] - p1[1]}) &&
               isVertical({p3[0] - p4[0], p3[1] - p4[1]}, {p2[0] - p4[0], p2[1] - p4[1]});
    }
};