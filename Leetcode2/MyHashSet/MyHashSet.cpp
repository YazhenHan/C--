class MyHashSet {
private:
    bool flag[1000000]= {false};
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }
    
    void add(int key) {
        flag[key] = true;
    }
    
    void remove(int key) {
        flag[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return flag[key];
    }
};