#include <string>

using namespace std;

class Trie {
private:
    struct node {
        bool flag;
        node* nodes[26];
        node() {
            flag = false;
            for (auto & node : nodes)
                node = nullptr;
        }
    };
    node* root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node * temp = root;
        for (auto c : word) {
            if (temp->nodes[c - 'a'] == nullptr)
                temp->nodes[c - 'a'] = new node();
            temp = temp->nodes[c - 'a'];
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        node * temp = root;
        for (auto c : word) {
            if (temp->nodes[c - 'a'] == nullptr)
                return false;
            temp = temp->nodes[c - 'a'];
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        node * temp = root;
        for (auto c : prefix) {
            if (temp->nodes[c - 'a'] == nullptr)
                return false;
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