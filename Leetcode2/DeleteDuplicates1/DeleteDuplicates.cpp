struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *pre = head, *cur = head;
        while (cur != nullptr)
        {
            if (cur->val != pre->val)
            {
                pre->next = cur;
                pre = pre->next;
            }
            cur = cur->next;
            if (cur == nullptr)
                pre->next = nullptr;
        }
        return head;
    }
};