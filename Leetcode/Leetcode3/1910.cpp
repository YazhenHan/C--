#include <string>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int a = -1;
        while ((a = s.find(part)) != -1) {
            string temp;
            for (int i = 0; i < a; i++) temp.push_back(s[i]);
            for (int i = a + part.size(); i < s.size(); i++) temp.push_back(s[i]);
            s = temp;
        }
        return s;
    }
};