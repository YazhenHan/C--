#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        vector<int> minCursors;
        vector<int> forRes(N, 0);
        if (ratings[0] <= ratings[1])
        {
            minCursors.push_back(0);
            forRes[0] = 1;
        }
        for (int i = 1; i + 1 < N; i++)
        {
            if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1])
            {
                minCursors.push_back(i);
                forRes[i] = 1;
            }
        }
        if (ratings[N - 1] <= ratings[N - 2])
        {
            minCursors.push_back(N - 1);
            forRes[N - 1] = 1;
        }
        for (auto minCursor : minCursors)
        {
            for (int left = minCursor - 1; left >= 0; left--)
            {
                if (ratings[left] > ratings[left + 1])
                {
                    forRes[left] = max(forRes[left], forRes[left + 1] + 1);
                }
                else if (ratings[left] == ratings[left + 1])
                {
                    forRes[left] = max(forRes[left], 1);
                }
                else
                {
                    break;
                }
            }
            for (int right = minCursor + 1; right < N; right++)
            {
                if (ratings[right] > ratings[right - 1])
                {
                    forRes[right] = max(forRes[right], forRes[right - 1] + 1);
                }
                else if (ratings[right] == ratings[right - 1])
                {
                    forRes[right] = max(forRes[right], 1);
                }
                else
                {
                    break;
                }
                
            }
        }
        int ans = 0;
        for (auto res : forRes)
            ans += res;
        return ans;
    }
};