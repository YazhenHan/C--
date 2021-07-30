#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    bool isOb(vector<int> xy, set<vector<int>>& s) {
        if (s.find(xy) == s.end())
            return false;
        return true;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int res = 0;
        int flag = 0;
        set<vector<int>> s;
        for (auto obstacle : obstacles)
            s.insert(obstacle);
        for (auto command : commands) {
            switch (command)
            {
            case -2:
                flag = (flag - 1 + 4) % 4;
                break;
            case -1:
                flag = (flag + 1) % 4;
                break;
            default:
                for (int i = 0; i < command; i++)
                {
                    switch (flag)
                    {
                    case 0:
                        y++;
                        break;
                    case 1:
                        x++;
                        break;
                    case 2:
                        y--;
                        break;
                    case 3:
                        x--;
                        break;
                    default:
                        break;
                    }
                    if (isOb({x,y}, s))
                    {
                        switch (flag)
                        {
                        case 0:
                            y--;
                            break;
                        case 1:
                            x--;
                            break;
                        case 2:
                            y++;
                            break;
                        case 3:
                            x++;
                            break;
                        default:
                            break;
                        }
                        break;
                    }
                }
                if (x * x + y * y > res)
                    res = x * x + y * y;
                break;
            }
        }
        return res;
    }
};