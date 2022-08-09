#include <vector>
#include <ctime>
#include <cstdlib>

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
    vector<int> list;
public:
    Solution(ListNode* head) {
        srand(time(0));
        while (head != nullptr) {
            list.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return list[rand() % list.size()];
    }
};

class Solution {
private:
    ListNode* head;
public:
    Solution(ListNode* head) : head(head) {
        srand(time(0));
    }
    
    int getRandom() {
        int ans = 0, i = 1;
        for (auto* temp = head; temp != nullptr; temp = temp->next) {
            if (rand() % i == 0)
                ans = temp->val;
            i++;
        }
        return ans;
    }
};