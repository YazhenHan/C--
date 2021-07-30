#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> umap;
        unordered_set<char> uset = {'!','?','\'',',',';','.',' '};
        int left = 0;
        string res;
        int forRes = INT32_MIN;
        for (int right = 0; right < paragraph.size(); right++)
        {
            paragraph[right] = tolower(paragraph[right]);
            if (uset.find(paragraph[right]) != uset.end() || (right == paragraph.size() - 1 && isalpha(paragraph[right])))
            {
                string temp = paragraph.substr(left, right - left);
                if (right == paragraph.size() - 1 && isalpha(paragraph[right]))
                    temp = paragraph.substr(left, ++right - left);
                left = right;
                while (left < paragraph.size() && !isalpha(paragraph[left])) left++;
                right = left - 1;
                if (find(banned.begin(), banned.end(), temp) != banned.end())
                    continue;
                if (umap.find(temp) == umap.end())
                {
                    umap.insert({temp, 1});
                    if (forRes == INT32_MIN)
                    {
                        res = temp;
                        forRes = 1;
                    }
                }
                else
                {
                    umap[temp]++;
                    if (umap[temp] > forRes)
                    {
                        res = temp;
                        forRes = umap[temp];
                    }
                }
            }
        }
        return res;
    }
};