#include <string>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        string cs, ns;
        for (auto c : s) {
            if (isdigit(c))
                ns.push_back(c);
            else
                cs.push_back(c);
        }
        string ans;
        if (abs(int(cs.size() - ns.size())) > 1) 
            ans =  "";
        else if (cs.size() == ns.size() + 1) {
            for (int i = 0; i < ns.size(); i++) {
                ans.push_back(cs[i]);
                ans.push_back(ns[i]);
            }
            ans.push_back(cs.back());
        } else if (cs.size() == ns.size() - 1) {
            for (int i = 0; i < cs.size(); i++) {
                ans.push_back(ns[i]);
                ans.push_back(cs[i]);
            }
            ans.push_back(ns.back());
        } else {
            for (int i = 0; i < cs.size(); i++) {
                ans.push_back(ns[i]);
                ans.push_back(cs[i]);
            }
        }
        return ans;
    }
};