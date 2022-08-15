#include <vector>
#include <string>

using namespace std;

class OrderedStream {
private:
    int ptr;
    vector<string> vs;
public:
    OrderedStream(int n) {
        ptr = 1;
        vs.resize(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        vs[idKey] = value;
        if (ptr != idKey) return ans;
        while (ptr < vs.size() && !vs[ptr].empty()) {
            ans.emplace_back(vs[ptr]);
            ptr++;
        }
        return ans;
    }
};