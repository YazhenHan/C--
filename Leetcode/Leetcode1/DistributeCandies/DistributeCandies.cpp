#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int res = 1;
        sort(candies.begin(),candies.end());
        for (int i = 0; i < candies.size() - 1; i++)
        {
            if (res == candies.size() / 2)
            {
                break;
            }
            if (candies[i] != candies[i + 1])
            {
                ++res;
            }
        }
        return res;
    }
};

int main() {

}