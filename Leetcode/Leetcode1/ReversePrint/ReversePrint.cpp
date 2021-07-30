#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head != nullptr)
        {
            res.push_back(head->val);
            head = head->next;
        }
            
        for (int i = 0; i < res.size() / 2; i++)
            swap(res[i], res[res.size() - 1 - i]);
        return res;
    }

    // example
    vector<int> reversePrint(ListNode* head) {
        if(!head)
            return {};
        vector<int> a = reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};