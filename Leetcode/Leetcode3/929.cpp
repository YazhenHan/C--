#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;
        for (auto && email : emails) {
            string temp;
            bool flag = false;
            int i = 0;
            while (i < email.size() && email[i] != '@') {
                if (email[i] == '.') { i++; continue; }
                else if (email[i] == '+') flag = true;
                if (flag) { i++; continue; }
                temp.push_back(email[i]);
                i++;
            }
            while (i < email.size()) {
                temp.push_back(email[i]);
                i++;
            }
            ans.insert(temp);
        }
        return ans.size();
    }
};