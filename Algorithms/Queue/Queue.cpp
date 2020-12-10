#include <iostream>

struct queue {
private:
    int* q;    
    int len;
    int front;
    int rear;
public:
    queue(int x) : len(x), front(0), rear(0) {
        q = (int*)malloc(x * sizeof(int));
    }
    void push(int x) {
        q[rear] = x;
        rear = (rear + 1) % len;
    }
    int pop() {
        front = (front + 1) % len;
        return q[(front - 1 + len) % len];
    }
};

int main()
{
    queue* q = new queue(5);
    for (int i = 0; i < 10; i++)
    {
        q->push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << q->pop() << " ";
    }
    std::cout << std::endl;
    return 0;
}