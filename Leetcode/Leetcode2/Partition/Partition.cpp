struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return nullptr;
        
        ListNode* head1 = nullptr, *head2 = nullptr, *res = nullptr, *ress = nullptr;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                if (head1 == nullptr)
                {
                    head1 = new ListNode(head->val);
                    res = head1;
                } else
                {
                    head1->next = new ListNode(head->val);
                    head1 = head1->next;
                }
            } else {
                if (head2 == nullptr)
                {
                    head2 = new ListNode(head->val);
                    ress = head2;
                } else
                {
                    head2->next = new ListNode(head->val);
                    head2 = head2->next;
                }
            }
            head = head->next;
        }
        if (res == nullptr)
            return ress;
        
        head1->next = ress;
        return res;
    }
};