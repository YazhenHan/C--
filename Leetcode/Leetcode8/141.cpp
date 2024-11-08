struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode * slow = head, * fast = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
                return true;
        } while (fast != nullptr && fast->next != nullptr);
        return false;
    }
};