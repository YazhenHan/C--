#include <vector>

using namespace std;

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
        ListNode* tail = head;
        int i = 0;
        while (i < k && tail != nullptr) {
            tail = tail->next;
            i++;
        }
        if (i == k) {
            ListNode* h = head, * hn = head->next;
            while (hn != tail) {
                auto temp = hn->next;
                hn->next = h;
                h = hn;
                hn = temp;
            }
            head->next = reverseKGroup(tail, k);
            return h;
        }
        return head;
    }
};