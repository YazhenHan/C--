class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<Node*, Node*> um;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (um.count(head)) return um[head];
        Node * ans = new Node(head->val);
        um[head] = ans;
        ans->next = copyRandomList(head->next);
        ans->random = copyRandomList(head->random);
        return ans;
    }
};