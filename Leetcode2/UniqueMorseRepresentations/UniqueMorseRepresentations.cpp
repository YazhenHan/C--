#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string smap[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> uset;
        for (auto word : words)
        {
            string temp;
            for (auto c : word)
                temp.append(smap[c - 'a']);
            if (uset.find(temp) == uset.end())
                uset.insert(temp);
        }
        return uset.size();
    }
};