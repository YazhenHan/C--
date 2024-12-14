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
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode * temp = new ListNode(), * ans = temp;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != nullptr) temp->next = list1;
        else temp->next = list2;
        return ans->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* ans = lists.front();
        for (int i = 1; i < lists.size(); i++) {
            ans = mergeLists(ans, lists[i]);
        }
        return ans;
    }
};