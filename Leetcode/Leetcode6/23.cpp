#include <vector>
#include <queue>

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
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != nullptr) temp->next = list1;
        if (list2 != nullptr) temp->next = list2;
        return ans->next;
    }

    ListNode* merge(vector<ListNode*> & lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return merge(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

class Solution {
private:
    struct Status {
        int val;
        ListNode * ptr;
        bool operator < (const Status & rhs) const {
            return val > rhs.val;
        }
    };
    priority_queue<Status> pq;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto list : lists)
            if (list)
                pq.push({list->val, list});
        ListNode head, * tail = &head;
        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next)
                pq.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};