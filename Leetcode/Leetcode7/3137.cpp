#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> um;
        int temp = INT32_MIN;
        for (int i = 0; i < word.size(); i += k) {
            um[word.substr(i, k)]++;
            temp = max(temp, um[word.substr(i, k)]);
        }
        return word.size() / k - temp;
    }
};