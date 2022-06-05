#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
private:
    double radius, x_center, y_center;
    bool isInCircle(vector<double> ans) {
        return (ans[0] - x_center) * (ans[0] - x_center) + (ans[1] - y_center) * (ans[1] - y_center) <= radius * radius;
    }
public:
    Solution(double radius, double x_center, double y_center) {
        srand(time(0));
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        vector<double> ans;
        do
        {
            ans.clear();
            double x = rand() / double(RAND_MAX) * (radius * 2) + x_center - radius;
            double y = rand() / double(RAND_MAX) * (radius * 2) + y_center - radius;
            ans.push_back(x);
            ans.push_back(y);
        } while (!isInCircle(ans));
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */