struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head != nullptr)
        {
            res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};