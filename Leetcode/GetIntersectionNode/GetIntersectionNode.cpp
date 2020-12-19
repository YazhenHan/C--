struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alength = 0, blength = 0;
        ListNode *heada = headA, *headb = headB;
        while (headA != nullptr)
        {
            headA = headA->next;
            alength++;
        }
            
        while (headB != nullptr)
        {
            headB = headB->next;
            blength++;
        }
        
        while (alength > blength)
        {
            heada = heada->next;
            alength--;
        }
        
        while (blength > alength)
        {
            headb = headb->next;
            blength--;
        }
        
        while (heada != headb)
        {
            heada = heada->next;
            headb = headb->next;
        }
        
        return heada;
        
    }
};