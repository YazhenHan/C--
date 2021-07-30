class MyHashMap {
private:
    int flag[1000001];
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for (auto &f : flag)
            f = -1;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        flag[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return flag[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        flag[key] = -1;
    }
};