#include <string>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed.size() < name.size())
            return false;
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size())
        {
            if (name[i] == typed[j])
            {
                i++;
                j++;
                continue;
            }
            if (i > 0 && name[i - 1] == typed[j])
            {
                j++;
                continue;
            }
            return false;
        }
        if (i < name.size())
            return false;
        while (j < typed.size())
        {
            if (typed[j] != name[i - 1])
                return false;
            j++;
        }
        return true;
    }
};