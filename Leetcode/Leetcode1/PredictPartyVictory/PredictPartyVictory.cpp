#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int ds = 0,rs = 0;
        int dss = 0,rss = 0;
        for (auto c : senate) {
            switch (c)
            {
            case 'R':
                rss++;
                break;
            case 'D':
                dss++;
                break;
            default:
                break;
            }
        }
        while (true)
        {
            for (auto &c : senate) {
                if (c == 'R') {
                    if (ds > 0) {
                        c = 0;
                        ds--;
                        rss--;
                    } else {
                        rs++;
                    }
                } else if (c == 'D') {
                    if (rs > 0) {
                        c = 0;
                        rs--;
                        dss--;
                    } else {
                        ds++;
                    }
                }
            }
            if (dss == 0 || rss == 0) {
                break;
            }
        }
        if (dss > 0) {
            return "Dire";
        }
        return "Radiant";
    }
};

int main() {
    Solution sol;
    std::cout << sol.predictPartyVictory("DRRDRDRDRDDRDRDR") << std::endl;
    return 0;
}