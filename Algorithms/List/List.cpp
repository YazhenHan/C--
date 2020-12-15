#include <iostream>

template <typename T>
class List
{
private:
    struct Node {
        T val;
        Node* next = nullptr;
        Node(T val, Node* &tail, Node* &head) : val(val) {
            if (tail == nullptr)
                tail = head = this;
            tail = tail->next = this;
        }
    };
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    void put(T val) {
        new Node(val, tail, head);
        return;
        // if (tail == nullptr)
        //     tail = head = new Node(val);
        // else
        //     tail = tail->next = new Node(val);
    }
    T get() {
        if (head == nullptr)
            return 0;
        Node* tempPtr = head;
        head = head->next;
        int temp = tempPtr->val;
        free(tempPtr);
        return temp;
    }
};

int main() {
    List<int> list;
    list.put(1);
    list.put(2);
    list.put(3);
    std::cout << list.get() << std::endl;
    std::cout << list.get() << std::endl;
    std::cout << list.get() << std::endl;
    return 0;
}