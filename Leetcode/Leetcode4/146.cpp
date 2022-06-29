#include <unordered_map>

using namespace std;

struct DLinkedNode
{
    int key, value;
    DLinkedNode * prev, * next;
    DLinkedNode(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
    DLinkedNode() {
        this->key = 0;
        this->value = 0;
        prev = nullptr;
        next = nullptr;
    }
};


class LRUCache {
private:
    unordered_map<int, DLinkedNode*> um;
    DLinkedNode * head, * end;
    int capacity;
    void erase(DLinkedNode * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return;
    }
    DLinkedNode * insert(int key, int value) {
        DLinkedNode * node = new DLinkedNode(key, value);
        end->prev->next = node;
        node->prev = end->prev;
        end->prev = node;
        node->next = end;
        return node;
    }
public:
    LRUCache(int capacity) {
        head = new DLinkedNode();
        end = new DLinkedNode();
        head->next = end;
        end->prev = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!um.count(key)) return -1;
        int value = um[key]->value;
        erase(um[key]);
        um[key] = insert(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (um.count(key)) {
            um[key]->value = value;
            erase(um[key]);
        } else if (um.size() == capacity) {
            um.erase(head->next->key);
            erase(head->next);
        }
        um[key] = insert(key, value);
    }
};