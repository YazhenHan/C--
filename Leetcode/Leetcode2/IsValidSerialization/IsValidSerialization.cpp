#include <string>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = 1;
        int flag = true;
        for (auto c : preorder)
        {
            if (flag && c >= '0' && c <= '9')
            {
                if (n == 0)
                    return false;
                n++;
                flag = false;
            }
            if (flag && c == '#')
            {
                if (n == 0)
                    return false;
                n--;
                flag = false;
            }
            if (c == ',')
                flag = true;
        }
        return n == 0;
    }
};