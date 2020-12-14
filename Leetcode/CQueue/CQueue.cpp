#include <stack>
#include <iostream>

using namespace std;

class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s2.push(value);
    }
    
    int deleteHead() {
        if (!s1.empty())
        {
            int temp = s1.top();
            s1.pop();
            return temp;
        }
        if (s2.empty())
        {
            return -1;
        }
        
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return deleteHead();
    }
};

int main()
{
    CQueue* obj = new CQueue();
    obj->appendTail(3);
    obj->appendTail(4);
    int param_2 = obj->deleteHead();
    std::cout << param_2 << std::endl;
    param_2 = obj->deleteHead();
    std::cout << param_2 << std::endl;
    param_2 = obj->deleteHead();
    std::cout << param_2 << std::endl;
    return 0;
}