struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * head1 = list1, * head2 = list2;
        ListNode * ans = new ListNode(0), * temp = ans;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if (head1 != nullptr) temp->next = head1;
        if (head2 != nullptr) temp->next = head2;
        return ans->next;
    }
};