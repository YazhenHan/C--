#include <vector>

using namespace std;

class Solution {
private:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<int> a = coordinates[0];
        vector<int> b = coordinates[1];
        int aa = b[0] - a[0];
        int bb = b[1] - a[1];
        for (int i = 2; i < coordinates.size(); i++)
        {
            vector<int> temp = coordinates[i];
            vector<int> temp2 = coordinates[i - 1];
            int a = temp[0] - temp2[0];
            int b = temp[1] - temp2[1];
            if (aa * b != a * bb)
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if (points[0] == points[1] || points[1] == points[2] || points[0] == points[2])
            return false;
        if (checkStraightLine(points))
            return false;
        return true;
    }
};