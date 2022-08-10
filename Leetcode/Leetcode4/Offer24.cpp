struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* hn = head->next;
        head->next = NULL;
        while (hn != NULL) {
            auto temp = hn->next;
            hn->next = head;
            head = hn;
            hn = temp;
        }
        return hn;
    }
};