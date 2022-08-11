#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1, ver2;
        int left = 0;
        for (int right = 0; right < version1.size(); right++) {
            if (version1[right] == '.') {
                ver1.push_back(stoi(version1.substr(left, right - left)));
                left = right + 1;
            }
            if (right == version1.size() - 1) {
                ver1.push_back(stoi(version1.substr(left, right - left + 1)));
                left = right + 1;
            }
        }
        left = 0;
        for (int right = 0; right < version2.size(); right++) {
            if (version2[right] == '.') {
                ver2.push_back(stoi(version2.substr(left, right - left)));
                left = right + 1;
            }
            if (right == version2.size() - 1) {
                ver2.push_back(stoi(version2.substr(left, right - left + 1)));
                left = right + 1;
            }
        }
        while (ver1.size() < ver2.size()) ver1.push_back(0);
        while (ver2.size() < ver1.size()) ver2.push_back(0);
        for (int i = 0; i < ver1.size(); i++) {
            if (ver1[i] < ver2[i])
                return -1;
            if (ver1[i] > ver2[i])
                return 1;
        }
        return 0;
    }
};