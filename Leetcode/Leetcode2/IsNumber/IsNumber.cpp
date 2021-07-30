#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        vector<unordered_map<char, int>> states;
        unordered_map<char, int> state0, state1, state2, state3, state4, state5, state6, state7, state8;
        
        state0.insert({' ', 0});
        state0.insert({'s', 1});
        state0.insert({'d', 2});
        state0.insert({'.', 4});
        states.push_back(state0);

        state1.insert({'d', 2});
        state1.insert({'.', 4});
        states.push_back(state1);

        state2.insert({'d', 2});
        state2.insert({'.', 3});
        state2.insert({'e', 5});
        state2.insert({' ', 8});
        states.push_back(state2);

        state3.insert({'d', 3});
        state3.insert({'e', 5});
        state3.insert({' ', 8});
        states.push_back(state3);

        state4.insert({'d', 3});
        states.push_back(state4);

        state5.insert({'s', 6});
        state5.insert({'d', 7});
        states.push_back(state5);

        state6.insert({'d', 7});
        states.push_back(state6);

        state7.insert({'d', 7});
        state7.insert({' ', 8});
        states.push_back(state7);

        state8.insert({' ', 8});
        states.push_back(state8);

        int p = 0;
        char t;
        for (auto c : s)
        {
            if (c >= '0' && c <= '9')
                t = 'd';
            else if (c == '+' || c == '-')
                t = 's';
            else if (c == 'e' || c == 'E')
                t = 'e';
            else if (c == '.' || c == ' ')
                t = c;
            else
                t = '?';
            if (states[p].find(t) == states[p].end())
                return false;
            p = states[p][t];
        }

        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};