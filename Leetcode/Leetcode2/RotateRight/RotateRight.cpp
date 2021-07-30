struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* head2 = head;
        int num = 1;
        while (head2->next != nullptr)
        {
            head2 = head2->next;
            num++;
        }
        head2->next = head;
        k = k % num;

        head2 = head;
        for (int i = 1; i < num - k; i++)
            head2 = head2->next;
        
        ListNode* ans = head2->next;
        head2->next = nullptr;
        return ans;
    }
};