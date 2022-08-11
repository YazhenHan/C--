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
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(), * temp = ans;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        if (list1 != nullptr) temp->next = list1;
        if (list2 != nullptr) temp->next = list2;
        return ans->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* head = lists.front();
        for (int i = 1; i < lists.size(); i++) {
            head = merge(head, lists[i]);
        }
        return head;
    }
};