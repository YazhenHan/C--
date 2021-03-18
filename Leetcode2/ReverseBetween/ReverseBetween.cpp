struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* pre = dummyNode;
        for (int i = 0; i < left - 1; i++)
            pre = pre->next;
        ListNode* cur = pre->next;
        ListNode* nex;
        for (int i = 0; i < right - left; i++)
        {
            nex = cur->next;
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return dummyNode->next;
    }
};