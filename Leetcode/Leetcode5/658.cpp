#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0;
        while (i < arr.size() && arr[i] < x)
            i++;
        deque<int> d;
        int left = i - 1, right = i;
        while (d.size() < k) {
            if (left < 0) {
                d.push_back(arr[right]);
                right++;
                continue;
            } else if (right >= arr.size()) {
                d.push_front(arr[left]);
                left--;
                continue;
            }
            if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                d.push_front(arr[left]);
                left--;
            } else {
                d.push_back(arr[right]);
                right++;
            }
        }
        return vector<int>(d.begin(), d.end());
    }
};