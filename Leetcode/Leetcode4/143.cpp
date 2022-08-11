struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode * reverse(ListNode * head) {
        ListNode * prev = nullptr;
        while (head != nullptr) {
            ListNode * temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        while (head != nullptr) {
            head->next = reverse(head->next);
            head = head->next;
        }
    }
};