#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> uset = {'a','e','i','o','u','A','E','I','O','U'};
        string ans;
        int count = 1;
        int left = 0;
        for (int right = 0; right < S.size(); right++)
        {
            if (right + 1 == S.size() || S[right + 1] == ' ')
            {
                if (uset.find(S[left]) != uset.end())
                {
                    for (int i = left; i <= right; i++)
                    {
                        ans.push_back(S[i]);
                    }
                }
                else
                {
                    for (int i = left + 1; i <= right; i++)
                    {
                        ans.push_back(S[i]);
                    }
                    ans.push_back(S[left]);
                }
                left = right + 2;
                ans.append("ma");
                for (int i = 0; i < count; i++)
                    ans.push_back('a');
                if (right == S.size() - 1)
                {
                    ans.push_back(' ');
                }
                count++;
            }
        }
        return ans;
    }
};