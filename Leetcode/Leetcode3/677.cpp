#include <string>
#include <unordered_map>

using namespace std;

class MapSum {
private:
    unordered_map<string, int> um;
    unordered_map<string, int> um2;
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        if (um.find(key) != um.end())
            for (int i = 1; i <= key.size(); i++)
                um2[key.substr(0, i)] -= um[key];
        um[key] = val;
        for (int i = 1; i <= key.size(); i++)
            if (um2.find(key.substr(0, i)) != um2.end())
                um2[key.substr(0, i)] += val;
            else
                um2[key.substr(0, i)] = val;
    }
    
    int sum(string prefix) {
        return um2[prefix];
    }
};