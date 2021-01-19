#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        unordered_set<int> us;
        if (x == 1)
        {
            for (int j = 0; ; j++)
            {
                int temp = 1 + pow(y, j);
                if (temp > bound)
                {
                    break;
                }
                if (us.find(temp) != us.end())
                {
                    if (temp == ans.back() && j != 0)
                    {
                        break;
                    }
                    continue;
                }
                ans.push_back(temp);
                us.insert(temp);
            }
            return ans;
        }

        if (y == 1)
        {
            for (int j = 0; ; j++)
            {
                int temp = 1 + pow(x, j);
                if (temp > bound)
                {
                    break;
                }
                if (us.find(temp) != us.end())
                {
                    if (temp == ans.back() && j != 0)
                    {
                        break;
                    }
                    continue;
                }
                ans.push_back(temp);
                us.insert(temp);
            }
            return ans;
        }
        
        for (int i = 0; ; i++)
        {
            int temp = pow(x, i) + pow(y, 0);
            if (temp > bound)
            {
                break;
            }
            for (int j = 0; ; j++)
            {
                int temp = pow(x, i) + pow(y, j);
                if (temp > bound)
                {
                    break;
                }
                if (us.find(temp) != us.end())
                {
                    continue;
                }
                ans.push_back(temp);
                us.insert(temp);
            }
        }
        return ans;
    }
};