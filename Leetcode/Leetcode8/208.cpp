#include <string>

using namespace std;

class Trie {
private:
    struct node {
        bool s = false;
        node* nodes[26] = {};
    };
    node* head;
public:
    Trie() {
        head = new node();
    }
    
    void insert(string word) {
        node* temp = head;
        for (auto c : word) {
            if (temp->nodes[c - 'a'] == nullptr)
                temp->nodes[c - 'a'] = new node();
            temp = temp->nodes[c - 'a'];
        }
        temp->s = true;
    }
    
    bool search(string word) {
        node* temp = head;
        for (auto c : word) {
            if (temp->nodes[c - 'a'] == nullptr) return false;
            temp = temp->nodes[c - 'a'];
        }
        return temp->s;
    }
    
    bool startsWith(string prefix) {
        node* temp = head;
        for (auto c : prefix) {
            if (temp->nodes[c - 'a'] == nullptr) return false;
            temp = temp->nodes[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */