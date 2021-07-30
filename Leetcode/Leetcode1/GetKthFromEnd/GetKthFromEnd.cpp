struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* head2 = head;
        for (int i = 0; i < k; i++)
            head2 = head2->next;
        while (head2 != nullptr)
        {
            head = head->next;
            head2 = head2->next;
        }
        return head;
    }
};