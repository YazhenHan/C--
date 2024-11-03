#include <string>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int leftS = 0, rightS = start.size() - 1, leftT = 0, rightT = target.size() - 1;
        int sum1 = 0, sum2 = 0;
        for (auto c : start) {
            if (c != '_')
                sum1++;
        }
        for (auto c : target) {
            if (c != '_')
                sum2++;
        }
        if (sum1 != sum2) return false;
        if (sum1 == 0) return true;
        while (leftT <= rightT) {
            while (target[leftT] == '_') leftT++;
            while (target[rightT] == '_') rightT--;
            while (start[leftS] == '_') leftS++;
            while (start[rightS] == '_') rightS--;

            if (start[leftS] != target[leftT]) return false;
            if (start[leftS] == 'R' && leftS > leftT) return false;
            if (start[leftS] == 'L' && leftS < leftT) return false;

            if (start[rightS] != target[rightT]) return false;
            if (start[rightS] == 'R' && rightS > rightT) return false;
            if (start[rightS] == 'L' && rightS < rightT) return false;

            leftT++;
            rightT--;
            leftS++;
            rightS--;
        }
        return true;
    }
};