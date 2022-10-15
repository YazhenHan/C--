#include <vector>
#include <queue>

using namespace std;

// Out of time
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = nums.size() - 1; i >= 0; i--) {
            queue<int> t;
            while (!pq.empty() && pq.top() < nums[i]) {
                t.push(pq.top());
                pq.pop();
            }
            ans[i] = t.size();
            while (!t.empty()) {
                pq.push(t.front());
                t.pop();
            }
            pq.push(nums[i]);
        }
        return ans;
    }
};

class Solution {
private:
    vector<int> c;
    vector<int> a;
    void Init(int length) {
        c.resize(length, 0);
    }
    int LowBit(int x) {
        return x & -x;
    }
    void Update(int pos) {
        while (pos < c.size()) {
            c[pos] += 1;
            pos += LowBit(pos);
        }
    }
    int Query(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += c[pos];
            pos -= LowBit(pos);
        }
        return ret;
    }
    void Discretization(vector<int>& nums) {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }
    int getId(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> resultList;
        Discretization(nums);
        Init(nums.size() + 5);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int id = getId(nums[i]);
            resultList.push_back(Query(id - 1));
            Update(id);
        }
        reverse(resultList.begin(), resultList.end());
        return resultList;
    }
};