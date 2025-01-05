#include <vector>

using namespace std;

class ATM {
private:
    vector<int> v;
public:
    ATM() {
        v = vector<int>(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) v[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> temp = v;
        vector<int> ans(5, 0);
        int t = min(amount / 500, temp[4]);
        ans[4] = t;
        temp[4] -= t;
        amount -= t * 500;
        t = min(amount / 200, temp[3]);
        ans[3] = t;
        temp[3] -= t;
        amount -= t * 200;
        t = min(amount / 100, temp[2]);
        ans[2] = t;
        temp[2] -= t;
        amount -= t * 100;
        t = min(amount / 50, temp[1]);
        ans[1] = t;
        temp[1] -= t;
        amount -= t * 50;
        t = min(amount / 20, temp[0]);
        ans[0] = t;
        temp[0] -= t;
        amount -= t * 20;
        if (amount > 0) return {-1};
        v = temp;
        return ans;
    }
};