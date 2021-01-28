#include <string>

using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int time1[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int time2[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
        int year = 0, month = 0, day = 0;
        for (int i = 0; i < 4; i++)
            year = year * 10 + (date[i] - '0');
        for (int i = 5; i < 7; i++)
            month = month * 10 + (date[i] - '0');
        for (int i = 8; i < 10; i++)
            day = day * 10 + (date[i] - '0');
        int ans = 0;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            ans = time2[month - 1] + day;
        else
            ans = time1[month - 1] + day;
        return ans;
    }
};