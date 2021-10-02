#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    int cmp(const string& s1, const string& s2) {
        if (s1.size() > s2.size()) return 1;
        else if (s1.size() < s2.size()) return -1;
        else if (s1 > s2) return 1;
        else if (s1 < s2) return -1;
        else return 0;
    }
    void exch(vector<string>& nums, int i, int j) {
        string t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    int partition(vector<string>& nums, int lo, int hi) {
        int i = lo, j = hi + 1;
        string v = nums[lo];
        while (true) {
            while (cmp(nums[++i], v) == 1) if (i == hi) break;
            while (cmp(v, nums[--j]) == 1) if (j == lo) break;
            if (i >= j) break;
            exch(nums, i, j);
        }
        exch(nums, lo, j);
        return j;
    }
    string search(vector<string>& nums, int lo, int hi, int k) {
        if (hi <= lo) return nums[lo];
        int j = partition(nums, lo, hi);
        if (j == k) return nums[j];
        else if (j > k) return search(nums, lo, j - 1, k);
        else return search(nums, j + 1, hi, k);
    }
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        random_shuffle(nums.begin(), nums.end());
        return search(nums, 0, nums.size() - 1, k - 1);
    }
};