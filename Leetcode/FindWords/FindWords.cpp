#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isWord(string word) {
        int keyboard[26]{2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        for(int i = 0;i < word.size() - 1;i++) {
            if (keyboard[toupper(word[i]) - 65] != keyboard[toupper(word[i+1]) - 65])
            {
                return false;
            }
        }
        return true;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for(auto word : words) {
            if (isWord(word))
            {
                res.push_back(word);
            }
        }
        return res;
    }
};

int main() {
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    
    return 0;
}