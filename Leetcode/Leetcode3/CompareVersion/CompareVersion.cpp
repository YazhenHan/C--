#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        
        int left = 0;
        for (int right = 0; right <= version1.size(); right++) {
            if (right == version1.size() || version1[right] == '.') {
                v1.push_back(atoi(version1.substr(left, right).c_str()));
                left = right + 1;
            }
        }
        left = 0;
        for (int right = 0; right <= version2.size(); right++) {
            if (right == version2.size() || version2[right] == '.') {
                v2.push_back(atoi(version2.substr(left, right).c_str()));
                left = right + 1;
            }
        }

        left = 0;
        while (left < v1.size() && left < v2.size()) {
            if (v1[left] > v2[left])
                return 1;
            if (v1[left] < v2[left])
                return -1;
            left++;
        }
        
        while (left < v1.size()) {
            if (v1[left] != 0)
                return 1;
            left++;
        }
        while (left < v2.size()) {
            if (v2[left] != 0)
                return -1;
            left++;
        }

        return 0;
    }
};