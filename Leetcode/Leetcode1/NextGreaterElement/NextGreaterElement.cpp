#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        bool flag = false;
        bool flag2 = false;
        for(auto num1 : nums1) {
            flag = false;
            flag2 = false;
            for(auto num2 : nums2) {
                if (num1 == num2)
                {
                    flag = true;
                }
                if (flag && num2 > num1)
                {
                    res.push_back(num2);
                    flag2 = true;
                    break;
                }
            }
            if (!flag2)
            {
                res.push_back(-1);
            }
        }
        return res;
    }
};

int main() {

}