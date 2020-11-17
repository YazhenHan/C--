#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m;
        int b = n;
        for(auto op : ops) {
            if (a > op[0])
            {
                a = op[0];
            }
            if (b > op[1])
            {
                b = op[1];
            }
        }
        return a * b;
    }
};

int main() {

}