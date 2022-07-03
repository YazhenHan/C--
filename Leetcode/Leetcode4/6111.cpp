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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> vs(m, vector<int>(n, -1));
        if (m == 1 && n == 1) {vs[0][0] = head->val; return vs;}
        for (int k = 0; k <= min(m, n) / 2; k++) {
            for (int i = k, j = k; j < n - k - 1 && head != nullptr; j++)
            {
                vs[i][j] = head->val;
                head = head->next;
            }
            for (int i = k, j = n - k - 1; i < m - k - 1 && head != nullptr; i++)
            {
                vs[i][j] = head->val;
                head = head->next;
            }
            for (int i = m - k - 1, j = n - k - 1; j >= k + 1 && head != nullptr; j--)
            {
                vs[i][j] = head->val;
                head = head->next;
            }
            for (int i = m - k -1, j = k; i >= k + 1 && head != nullptr; i--)
            {
                vs[i][j] = head->val;
                head = head->next;
            }
        }
        return vs;
    }
};