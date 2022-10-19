#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i = 0, j = 0, temp = 0, m = students.size();
        while (i < students.size() && j < sandwiches.size()) {
            if (students[i] == sandwiches[j]) {
                j++;
                temp = 0;
            }
            else {
                students.push_back(students[i]);
                if (temp == 0)
                    m = students.size();
                temp++;
            }
            i++;
            if (m == temp)
                break;
        }
        return sandwiches.size() - j;
    }
};