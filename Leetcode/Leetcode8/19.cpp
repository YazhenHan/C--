struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr;
        ListNode * tail = head, * temp = head;
        for (int i = 0; i < n; i++) tail = tail->next;
        while (tail != nullptr && tail->next != nullptr) {
            temp = temp->next;
            tail = tail->next;
        }
        if (temp == head && tail == nullptr) return head->next;
        temp->next = temp->next->next;
        return head;
    }
};