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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* t = head;
        int len = 0;
        while (t != nullptr) {
            t = t->next;
            len++;
        }
        int l = len / k, a = len % k;
        vector<ListNode*> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(head);
            if (l == 0 &&  a == 0) continue;
            if (a > 0) {
                for (int j = 0; j < l + 1; j++) {
                    t = head;
                    head = head->next;
                }
                t->next = nullptr;
                a--;
            }
            else {
                for (int j = 0; j < l; j++) {
                    t = head;
                    head = head->next;
                }
                t->next = nullptr;
            }
        }
        return ans;
    }
};