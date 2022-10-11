#include <vector>
#include <unordered_set>

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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int count = 0;
        bool temp = false;
        while (head != nullptr) {
            if (us.count(head->val)) {
                if (!temp)
                    count++;
                temp = true;
            } else {
                temp = false;
            }
            head = head->next;
        }
        return count;
    }
};