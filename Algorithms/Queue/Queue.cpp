#include <iostream>

template <typename T>
struct queue {
private:
    T* q;    
    int len;
    int front;
    int rear;
public:
    queue(T x) : len(x), front(0), rear(0) {
        q = (T*)malloc(x * sizeof(T));
    }
    void push(T x) {
        q[rear] = x;
        rear = (rear + 1) % len;
    }
    T pop() {
        front = (front + 1) % len;
        return q[(front - 1 + len) % len];
    }
};

int main()
{
    queue q = new queue(6);
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