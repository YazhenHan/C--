struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * tempA = headA, * tempB = headB;
        int tA = 0, tB = 0;
        while (tempA != nullptr) {
            tA++;
            tempA = tempA->next;
        }
        while (tempB != nullptr) {
            tB++;
            tempB = tempB->next;
        }
        while (tA < tB) { 
            tA++;
            headB = headB->next; 
        }
        while (tB < tA) { 
            tB++;
            headA = headA->next; 
        }
        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};