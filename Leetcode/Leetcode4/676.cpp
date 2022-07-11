#include <vector>
#include <string>

using namespace std;

class MagicDictionary {
private:
    vector<string> dictionary;
    bool forAns(string& word, string& searchWord) {
        if (word.size() != searchWord.size())
            return false;
        int ans = 0;
        for (int i = 0; i < word.size(); i++)
            if (word[i] != searchWord[i])
                ans++;
        return ans == 1;
    }
public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        this->dictionary = dictionary;
    }
    
    bool search(string searchWord) {
        for (auto word : dictionary)
            if (forAns(word, searchWord))
                return true;
        return false;
    }
};