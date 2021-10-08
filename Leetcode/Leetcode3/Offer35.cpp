#define NULL 0
#include <unordered_map>
#include <memory>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> um;

        Node* ans = new Node(head->val);
        um.insert({head, ans});

        Node* h = head;
        Node* a = ans;
        while (head->next != NULL) {
            head = head->next;
            ans->next = new Node(head->val);
            ans = ans->next;
            um.insert({head, ans});
        }

        ans = a;

        while (h != NULL) {
            if (h->random == NULL) a->random = NULL;
            else a->random = um[h->random];
            h = h->next;
            a = a->next;
        }

        return ans;
    }
};