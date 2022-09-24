#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool ballGame(int num, const vector<string>& plate, int& i, int& j, int d) {
        for (int k = 0; k <= num; k++) {
            switch (d)
            {
            case 0:
                i--;
                break;
            case 1:
                j++;
                break;
            case 2:
                i++;
                break;
            case 3:
                j--;
                break;
            }
            if (i == -1) {
                if (j != 0 && j != plate[i + 1].size() - 1 && plate[0][j] == '.') { i = 0; return true; }
                else return false;
            }
            if (i == plate.size()) {
                if (j != 0 && j != plate[i - 1].size() - 1 && plate[plate.size() - 1][j] == '.') { i = plate.size() - 1; return true; }
                else return false;
            }
            if (j == -1) {
                if (i != 0 && i != plate.size() - 1 && plate[i][0] == '.') { j = 0; return true; }
                else return false;
            }
            if (j == plate[i].size()) {
                if (i != 0 && i != plate.size() - 1 && plate[i][plate[i].size() - 1] == '.') { j = plate[i].size() - 1; return true; }
                else return false;
            }
            switch (plate[i][j])
            {
            case 'E':
                d = (d - 1 + 4) % 4;
                break;
            case 'W':
                d = (d + 1) % 4;
                break;
            case 'O':
                return false;
            }
        }
        return false;
    }
public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        vector<vector<int>> ans;
        for (int i = 0; i < plate.size(); i++) {
            for (int j = 0; j < plate[i].size(); j++) {
                if (plate[i][j] == 'O') {
                    int ti = i, tj = j;
                    if (i != 0 && ballGame(num, plate, ti, tj, 0))
                        ans.push_back({ti, tj});
                    ti = i, tj = j;
                    if (j != plate[0].size() - 1 && ballGame(num, plate, ti, tj, 1))
                        ans.push_back({ti, tj});
                    ti = i, tj = j;
                    if (i != plate.size() - 1 && ballGame(num, plate, ti, tj, 2))
                        ans.push_back({ti, tj});
                    ti = i, tj = j;
                    if (j != 0 && ballGame(num, plate, ti, tj, 3))
                        ans.push_back({ti, tj});
                }
            }
        }
        return ans;
    }
};