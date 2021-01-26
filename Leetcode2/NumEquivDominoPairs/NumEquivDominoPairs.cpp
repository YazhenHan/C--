#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        for (auto& domino : dominoes)
        {
            if (domino[0] > domino[1])
            {
                int temp = domino[0];
                domino[0] = domino[1];
                domino[1] = temp;
            }
        }
        sort(dominoes.begin(), dominoes.end());
        for (size_t i = 0; i < dominoes.size(); i++)
        {
            int temp = 1;
            size_t j = i + 1;
            for (; j < dominoes.size(); j++)
                if (dominoes[j][0] == dominoes[i][0] && dominoes[j][1] == dominoes[i][1])
                    temp++;
                else
                    break;
            ans += (temp * (temp - 1)) / 2;
            i = j - 1;
        }
        return ans;
    }
};