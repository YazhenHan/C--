#include <string>

using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string ans;
        int num = 0;
        for (auto c : number)
            if (isdigit(c))
                num++;
        for (int i = 0; i < number.size();) {
            int t = 0;
            if (num == 4) {
                while (i < number.size() && t < 2) {
                    if (!isdigit(number[i])) {
                        i++;
                        continue;
                    }
                    ans.push_back(number[i]);
                    t++;
                    num--;
                    i++;
                }
            }
            else {
                while (i < number.size() && t < 3) {
                    if (!isdigit(number[i])) {
                        i++;
                        continue;
                    }
                    ans.push_back(number[i]);
                    t++;
                    num--;
                    i++;
                }
            }
            if (num > 0)
                ans.push_back('-');
        }
        return ans;
    }
};