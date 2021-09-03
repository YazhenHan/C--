#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        if (k == 0)
            return ans;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
            pq.push(arr[i]);
        for (int i = k; i < arr.size(); i++) {
            if (pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
