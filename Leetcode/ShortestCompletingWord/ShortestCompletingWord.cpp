#include<string>
#include<vector>

using namespace std;

class Solution {
private:
    int isRight(vector<int> flag, string word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (isupper(word[i])) {
                flag[word[i] - 65]--;
            }
            if (islower(word[i])) {
                flag[word[i] - 97]--;
            }
        }
        for (int i = 0; i < flag.size(); i++)
        {
            if (flag[i] > 0)
            {
                return INT32_MAX;
            }
        }
        return word.size();
    }
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> flag;
        for (int i = 0; i < 26; i++)
        {
            flag.push_back(0);
        }
        
        for (int i = 0; i < licensePlate.size(); i++)
        {
            if (isupper(licensePlate[i])) {
                flag[licensePlate[i] - 65]++;
            }
            if (islower(licensePlate[i])) {
                flag[licensePlate[i] - 97]++;
            }
        }

        int res = INT32_MAX;
        string resres;
        for(auto word : words) {
            int temp = isRight(flag, word);
            if (temp < res)
            {
                res = temp;
                resres = word;
            }
        }
        return resres;
    }
};