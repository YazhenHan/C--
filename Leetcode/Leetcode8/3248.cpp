#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for (const string & command : commands) {
            if (command == "RIGHT") {
                j++;
            } else if (command == "DOWN") {
                i++;
            } else if (command == "UP") {
                i--;
            } else {
                j--;
            }
        }
        return i * n + j;
    }
};