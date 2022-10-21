#include <stack>
#include <utility>

using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> sp;
    int c;
public:
    StockSpanner() {
        sp.push({INT32_MAX, 0});
        c = 0;
    }
    
    int next(int price) {
        c++;
        while (!sp.empty() && sp.top().first <= price)
            sp.pop();
        int ans = c - sp.top().second;
        sp.push({price, c});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */