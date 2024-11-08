struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head, * fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = slow->next;
        ListNode * prev = nullptr;
        while (slow != nullptr) {
            ListNode * next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        while (prev != nullptr && head != nullptr) {
            if (prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};