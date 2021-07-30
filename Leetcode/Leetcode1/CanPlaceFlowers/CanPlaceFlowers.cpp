#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n <= 0)
            return true;
            
        if (flowerbed[0] == 0 && (flowerbed.size() == 1 || flowerbed[1] == 0))
        {
            flowerbed[0] = 1;
            n--;
            if (n <= 0)
                return true;
        }
        if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0)
        {
            flowerbed[flowerbed.size() - 1] = 1;
            n--;
            if (n <= 0)
                return true;
        }
        
                
        for (int i = 1; i + 1 < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
            if (n <= 0)
                return true;
        }
        
        return false;
    }
};