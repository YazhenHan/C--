#include <string>
#include <utility>

using namespace std;

class Solution {
private:
    pair<int, int> getCom(string num) {
        int real = 0, vir = 0, i = 0;
        bool flag = false;
        for (; i < num.size(); i++) {
            if (num[i] == '-') { flag = true; continue; }
            if (num[i] == '+') break;
            real = real * 10 + (num[i] - '0');
        }
        if (flag) real = real * -1;
        flag = false;
        for (i++; i < num.size(); i++) {
            if (num[i] == '-') { flag = true; continue; }
            if (num[i] == 'i') break;
            vir = vir * 10 + (num[i] - '0');
        }
        if (flag) vir = vir * -1;
        return pair<int, int>(real, vir);
    }
public:
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> p1 = getCom(num1);
        pair<int, int> p2 = getCom(num2);
        cout << p1.first << " " << p1.second << endl;
        cout << p2.first << " " << p2.second << endl;
        int real = p1.first * p2.first - p1.second * p2.second;
        int vir = p1.first * p2.second + p1.second * p2.first;
        cout << real << " " << vir << endl;
        string ans;
        ans.append(to_string(real));
        ans.push_back('+');
        ans.append(to_string(vir));
        ans.push_back('i');
        return ans;
    }
};