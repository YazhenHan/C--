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
    ListNode* mergeNodes(ListNode* head) {
        int temp = 0;
        vector<int> v;
        while (head != nullptr) {
            if (head->val == 0 && temp != 0) {
                v.push_back(temp);
                temp = 0;
            }
            temp += head->val;
            head = head->next;
        }
        ListNode* ans = new ListNode();
        ListNode* t = ans;
        for (auto a : v) {
            t->next = new ListNode(a);
            t = t->next;
        }
        return ans->next;
    }
};