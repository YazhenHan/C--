#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int total = 0;
        for (size_t i = 0; i < customers.size(); i++)
            if (grumpy[i] == 0)
                total += customers[i];
        
        int largest = 0;
        for (size_t i = 0; i < X; i++)
            if (grumpy[i] == 1)
                largest += customers[i];
        
        int pre = largest;
        for (size_t i = X; i < customers.size(); i++)
        {
            int cur = pre;
            if (grumpy[i - X] == 1)
                cur -= customers[i - X];
            if (grumpy[i] == 1)
                cur += customers[i];
            if (cur > largest)
                largest = cur;
            pre = cur;
        }
        
        return total + largest;
    }
};