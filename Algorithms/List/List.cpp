#include <iostream>

template <typename T>
struct Node {
    T val;
    Node* next;
    // Node(T x) : val(x), next(nullptr) {}
};

int main() {
    int temp;
    std::cin >> temp;
    Node<int>* head = new Node<int>();
    head->val = temp;
    head->next = nullptr;
    Node<int>* head2 = head;
    while (std::cin >> temp)
    {
        Node<int>* tempNode = new Node<int>();
        tempNode->val = temp;
        tempNode->next = nullptr;
        head2->next = tempNode;
        head2 = head2->next;
    }
    while (head != nullptr) 
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
    return 0;
}