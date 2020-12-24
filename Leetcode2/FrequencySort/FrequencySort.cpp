#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool static isSort(pair<char, int>& count1, pair<char, int>& count2)
    {
        return count1.second > count2.second;
    }
    int findC(vector<pair<char, int>>& count, char c)
    {
        for (int cursor = 0; cursor < count.size(); cursor++)
            if (count[cursor].first == c)
                return cursor;
        return -1;
    }
public:
    string frequencySort(string s) {
        vector<pair<char, int>> count;
        for (auto c : s)
        {
            int temp = findC(count, c);
            if (temp == -1)
                count.push_back({c, 1});
            else
                count[temp].second++;
        }
        sort(count.begin(), count.end(), isSort);
        string ans;
        for (auto temp : count)
            for (int i = 0; i < temp.second; i++)
                ans.push_back(temp.first);
        return ans;
    }
};