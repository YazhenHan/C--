#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> um;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (um.count(key)) {
            l.push_front(*um[key]);
            l.erase(um[key]);
            um[key] = l.begin();
            return l.front().second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (um.count(key)) {
            l.erase(um[key]);
            l.push_front({key, value});
            um[key] = l.begin();
            return;
        }
        if (l.size() == capacity) {
            um.erase(l.back().first);
            l.pop_back();
        }
        l.push_front({key, value});
        um[key] = l.begin();
    }
};