struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode * slow = head, * fast = head;
        bool flag = false;
        do {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                flag = true;
                break;
            }
        } while (fast != nullptr && fast->next != nullptr);
        if (!flag) return nullptr;
        ListNode * ans = head;
        while (ans != slow) {
            ans = ans->next;
            slow = slow->next;
        }
        return ans;
    }
};