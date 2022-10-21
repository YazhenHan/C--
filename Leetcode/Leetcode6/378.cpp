#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        struct point {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y) {}
            bool operator > (const point & a) const { return this->val > a.val; }
        };
        priority_queue<point, vector<point>, greater<point>> pq;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            pq.emplace(matrix[i][0], i, 0);
        for (int i = 0; i < k - 1; i++) {
            point now = pq.top();
            pq.pop();
            if (now.y != n - 1)
                pq.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
        }
        return pq.top().val;
    }
};

class Solution {
private:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1, j = 0, num = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};