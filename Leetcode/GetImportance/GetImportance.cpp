#include <vector>

using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        int res = 0;
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i]->id == id)
            {
                res = employees[i]->importance;
                for (int j = 0; j < employees[i]->subordinates.size(); j++)
                {
                    res += getImportance(employees, employees[i]->subordinates[j]);
                }
                break;
            }
        }
        return res;
    }
};