class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
private:
    Node* getEnd(Node* head) {
        while (head != nullptr)
        {
            if (head->child != nullptr) {
                Node* t = getEnd(head->child);
                t->next = head->next;
                if (head->next != nullptr)
                    head->next->prev = t;
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
            }
            if (head->next == nullptr)
                return head;
            else
                head = head->next;
        }
        return nullptr;
    }
public:
    Node* flatten(Node* head) {
        getEnd(head);
        return head;
    }
};