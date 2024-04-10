#include <string>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int flag = -1, count = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0' && flag == -1) {
                flag = i;
            }
            if (flag != -1 && binary[i] == '1')
                count++;
        }
        for (int i = flag; i < binary.size(); i++)
            binary[i] = '0';
        for (int i = binary.size() - count; i < binary.size(); i++)
            binary[i] = '1';
            
        for (int i = 0; i < binary.size() - 1; i++) {
            if (binary[i] == '0' && binary[i + 1] == '0')
                binary[i] = '1';
        }
        return binary;
    }
};