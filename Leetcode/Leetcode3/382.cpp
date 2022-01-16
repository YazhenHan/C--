#include <vector>
#include <cstdlib>
#include <ctime>

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
    vector<int> h;

public:
    Solution(ListNode* head) {
        while (head != nullptr) {
            h.push_back(head->val);
            head = head->next;
        }
        srand((int)time(0));
    }
    
    int getRandom() {
        return h[rand() % h.size()];
    }
};