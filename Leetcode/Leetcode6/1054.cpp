#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

class Solution {
private:
    struct cmp
    {
        bool operator() (const pair<int, int> & p1, const pair<int, int> & p2) {
            return p1.second < p2.second;
        }
    };
    
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> um;
        for (int i = 0; i < barcodes.size(); i++) {
            um[barcodes[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pqp;
        for (auto t : um) {
            pqp.push(t);
        }
        vector<int> ans;
        while (!pqp.empty()) {
            auto t1 = pqp.top();
            if (ans.empty()) {
                ans.push_back(t1.first);
                t1.second--;
                pqp.pop();
                if (t1.second > 0) {
                    pqp.push(t1);
                }
            } else {
                if (ans.back() == t1.first) {
                    pqp.pop();
                    auto t2 = pqp.top();
                    ans.push_back(t2.first);
                    pqp.pop();
                    t2.second--;
                    if (t2.second > 0) {
                        pqp.push(t2);
                    }
                    pqp.push(t1);
                } else {
                    ans.push_back(t1.first);
                    t1.second--;
                    pqp.pop();
                    if (t1.second > 0) {
                        pqp.push(t1);
                    }
                }
            }
        }
        return ans;
    }
};