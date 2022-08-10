#include <string>

using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int leftnum = 0, leftx = 0, left = 0, i = 0;
        bool flagpn = true, flagx = false;
        while (true) {
            if (equation[i] == 'x') flagx = true;
            if (equation[i] == '+' || equation[i] == '-' || equation[i] == '=') {
                int temp = 0;
                if (flagx && left + 1 == i)
                    temp = 1;
                else 
                    for (int j = left; j < (flagx ? i - 1 : i); j++)
                        temp = temp * 10 + (equation[j] - '0');
                if (!flagpn) temp = -temp;
                if (flagx) leftx += temp;
                else leftnum += temp;
                flagpn = equation[i] == '+' ? true : false;
                flagx = false;
                left = i + 1;
            }
            if (equation[i] == '=')
                break;
            i++;
        }
        i++;
        int rightnum = 0, rightx = 0;
        flagpn = true;
        flagx = false;
        while (i < equation.size()) {
            if (equation[i] == 'x') flagx = true;
            if (equation[i] == '+' || equation[i] == '-' || i == equation.size() - 1) {
                int temp = 0;
                if (flagx && (i == equation.size() - 1 && left == i || i != equation.size() - 1 && left + 1 == i))
                    temp = 1;
                else
                    for (int j = left; j < (i == equation.size() - 1 ? (flagx ? i : i + 1) : (flagx ? i - 1 : i)); j++)
                        temp = temp * 10 + equation[j] - '0';
                if (!flagpn) temp = -temp;
                if (flagx) rightx += temp;
                else rightnum += temp;
                flagpn = equation[i] == '+' ? true : false;
                flagx = false;
                left = i + 1;
            }
            i++;
        }
        leftx = leftx - rightx;
        rightnum = rightnum - leftnum;
        if (leftx == 0 && rightnum == 0) return "Infinite solutions";
        if (leftx == 0 && rightnum != 0) return "No solution";
        return "x=" + to_string(rightnum / leftx);
    }
};