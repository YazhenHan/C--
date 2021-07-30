struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* pre = head;

        if (head == nullptr)
            return nullptr;
        
        if (head->val == val)
            return head->next;

        while (pre->next != nullptr && pre->next->val != val) {
            pre = pre->next;
        }
        
        pre->next = pre->next->next;

        return head;
    }

    ListNode* deleteNode(ListNode* head, int val) 
    {
        if (head == nullptr)
            return head;
        if (head->val == val)
            return head->next;
        head->next = deleteNode(head->next, val);
        return head;
    }
};