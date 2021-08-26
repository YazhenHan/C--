#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int ans = 0;
        while (left <= right) {
            int temp = people[left] + people[right];
            if (temp <= limit) {
                left++;
                right--;
            } else {
                right--;
            }
            ans++;
        }
        return ans;
    }
};

int main() {
    vector<int> people = { 1, 2 };
    Solution s;
    std::cout << s.numRescueBoats(people, 3) << std::endl;
    return 0;
}