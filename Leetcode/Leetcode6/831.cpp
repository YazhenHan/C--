#include <string>

using namespace std;

class Solution {
public:
    string maskPII(string s) {
        bool flag = isalpha(s[0]);
        string ans;
        if (flag) {
            int right = 0;
            while (right < s.size()) {
                if (s[right] == '@')
                    break;
                right++;
            }
            ans.push_back(s[0]);
            ans.append("*****" + s.substr(right - 1));
            for (int i = 0; i < ans.size(); i++)
                ans[i] = tolower(ans[i]);
        } else {
            string temp;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] >= '0' && s[i] <= '9')
                    temp.push_back(s[i]);
            }
            if (temp.size() > 10) ans.push_back('+');
            for (int i = 0; i < temp.size() - 10; i++)
                ans.push_back('*');
            if (temp.size() > 10) ans.append("-***-***-");
            else ans.append("***-***-");
            for (int i = temp.size() - 4; i < temp.size(); i++)
                ans.push_back(temp[i]);
        }
        return ans;
    }
};