#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    int partition(vector<int>& A,  vector<int>& B, int low, int high) {
        int pivot = A[low], pivot2 = B[low];
        while (low < high) {
            while (low < high && A[high] >= pivot)
            {
                --high;
            }
            A[low] = A[high];
            B[low] = B[high];
            while (low < high && A[low] <= pivot)
            {
                ++low;
            }
            A[high] = A[low];
            B[high] = B[low];
        }
        A[low] = pivot;
        B[low] = pivot2;
        return low;
    }

    void QuickSort(vector<int>& A, vector<int>& B, int low, int high) {
        if (low < high) {
            int pivot = partition(A, B, low, high);
            QuickSort(A, B, low, pivot - 1);
            QuickSort(A, B, pivot + 1, high);
        }
    }
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        QuickSort(values, labels, 0, n - 1);
        int ans = 0, ums = 0;
        unordered_map<int, int> um;
        for (int i = n - 1; i >= 0; i--) {
            if (um.find(labels[i]) == um.end()) {
                um.insert({labels[i], 1});
                ans += values[i];
                ums++;
            }
            else if (um[labels[i]] < useLimit) {
                um[labels[i]]++;
                ans += values[i];
                ums++;
            }
            if (ums == numWanted) {
                break;
            }
        }
        return ans;
    }
};