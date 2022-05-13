#include <string>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n1 = first.size(), n2 = second.size();
        if (n1 - n2 > 1 || n2 - n1 > 1) return false;
        if (n1 > n2) {
            int i = 0, j = 0, flag = 0;
            while(i < second.size()) {
                if (second[i] == first[j]) {
                    i++;
                    j++;
                } else {
                    flag++;
                    j++;
                }
                if (flag > 1) {
                    return false;
                }
            }
        } else if (n1 == n2) {
            int i = 0, j = 0, flag = 0;
            while(i < second.size()) {
                if (second[i] == first[j]) {
                    i++;
                    j++;
                } else {
                    i++;
                    j++;
                    flag++;
                }
                if (flag > 1) {
                    return false;
                }
            }
        } else {
            int i = 0, j = 0, flag = 0;
            while(i < first.size()) {
                if (first[i] == second[j]) {
                    i++;
                    j++;
                } else {
                    j++;
                    flag++;
                }
                if (flag > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};