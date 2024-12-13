struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * t = new ListNode(), * ans = t, * temp = head;
        int i = 1;
        while (temp != nullptr) {
            ListNode* cur = temp, * next = cur->next;
            cur->next = nullptr;
            i = 1;
            while (i < k && next != nullptr) {
                ListNode * te = next->next;
                next->next = cur;
                cur = next;
                next = te;
                i++;
            }
            if (i != k) {
                next = cur->next;
                cur->next = nullptr;
                while (next != nullptr) {
                    ListNode * te = next->next;
                    next->next = cur;
                    cur = next;
                    next = te;
                }
            }

            t->next = cur;
            t = temp;
            temp = next;
        }
        return ans->next;
    }
};