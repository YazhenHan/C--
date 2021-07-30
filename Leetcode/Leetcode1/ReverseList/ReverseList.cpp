struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* pre = head;
        head = head->next;
        ListNode* head2 = head->next;
        pre->next = nullptr;
        while (head2 != nullptr)
        {
            head->next = pre;
            pre = head;
            head = head2;
            head2 = head2->next;
        }
        head->next = pre;
        return head;
    }
};