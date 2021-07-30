#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    void forRes(string& cpdomain, unordered_map<string, int>& umap)
    {
        int ints = 0;
        int i = 0;
        while (cpdomain[i] != ' ')
        {
            ints = ints * 10 + cpdomain[i] - '0';
            i++;
        }
        while (i < cpdomain.size())
        {
            if (cpdomain[i] == ' ' || cpdomain[i] == '.')
            {
                string temp = cpdomain.substr(i + 1, cpdomain.size());
                if (umap.find(temp) == umap.end())
                    umap.insert({temp, ints});
                else
                    umap[temp] += ints;
            }
            i++;
        }
    }
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> umap;
        for (auto cpdomain : cpdomains)
            forRes(cpdomain, umap);
        vector<string> ans;
        for (auto tp : umap)
            ans.push_back(to_string(tp.second) + " " + tp.first);
        return ans;
    }
};