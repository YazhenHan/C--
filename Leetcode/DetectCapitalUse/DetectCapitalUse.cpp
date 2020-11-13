#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1)
        {
            return true;
        }
        bool flag = isupper(word[0]) ? true : false;
        bool flag2 = isupper(word[1]) ? true : false;
        if (flag)
        {
            if (flag2)
            {
                for (int i = 2; i < word.size(); i++)
                {
                    if (!isupper(word[i]))
                    {
                        return false;
                    }
                    
                }
            } else {
                for (int i = 2; i < word.size(); i++)
                {
                    if (isupper(word[i]))
                    {
                        return false;
                    }
                    
                }
            }
        } else {
            for (int i = 2; i < word.size(); i++)
            {
                if (isupper(word[i]))
                {
                    return false;
                }
                
            }
        }
        return true;
    }
};

int main() {
    return 0;
}