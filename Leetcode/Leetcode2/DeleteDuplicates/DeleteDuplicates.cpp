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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        vector<int> list;
        while (head != nullptr)
        {
            list.push_back(head->val);
            head = head->next;
        }

        vector<int> list2;
        for (int i = 1; i < list.size(); i++)
        {
            if (list[i] != list[i - 1])
            {
                if (i - 2 < 0 || list[i - 1] != list[i - 2])
                    list2.push_back(list[i - 1]);
                if (i == list.size() - 1)
                    list2.push_back(list[i]);
            }
        }

        if (list2.empty())
            return nullptr;
        ListNode* ans = new ListNode(list2[0]);
        ListNode* head2 = ans;
        for (int i = 1; i < list2.size(); i++)
        {
            ListNode* temp = new ListNode(list2[i]);
            head2->next = temp;
            head2 = temp;
        }
        return ans;
    }
};