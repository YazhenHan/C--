#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        int arr1[26] = {0}, arr2[26] = {0};
        for (int i = 0; i < word1.size(); i++) {
            arr1[word1[i] - 'a']++;
            arr2[word2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
            if (arr1[i] == 0 && arr2[i] != 0 || arr1[i] != 0 && arr2[i] == 0)
                return false;
        sort(begin(arr1), end(arr1));
        sort(begin(arr2), end(arr2));
        for (int i = 0; i < 26; i++)
            if (arr1[i] != arr2[i])
                return false;
        return true;
    }
};