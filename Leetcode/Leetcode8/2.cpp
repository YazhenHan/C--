struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans = new ListNode(0), * temp = ans;
        int flag = false;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + flag;
            if (sum >= 10) {
                flag = 1;
                temp->next = new ListNode(sum - 10);
            } else {
                flag = 0;
                temp->next = new ListNode(sum);
            }
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            int sum = l1->val + flag;
            if (sum >= 10) {
                flag = 1;
                temp->next = new ListNode(sum - 10);
            } else {
                flag = 0;
                temp->next = new ListNode(sum);
            }
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int sum = l2->val + flag;
            if (sum >= 10) {
                flag = 1;
                temp->next = new ListNode(sum - 10);
            } else {
                flag = 0;
                temp->next = new ListNode(sum);
            }
            temp = temp->next;
            l2 = l2->next;
        }
        if (flag) temp->next = new ListNode(1);

        return ans->next;
    }
};