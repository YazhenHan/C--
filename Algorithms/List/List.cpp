#include <iostream>

template <typename T>
struct Node {
    T val;
    Node<T> next;
    Node(T x) : val(x), next(nullptr) {}
};

int main() {
    int temp;
    std::cin >> temp;
    Node node = new Node(temp);
    while (std::cin >> temp)
    {
        Node tempNode = new Node(temp);
        node.next = tempNode;
        node = node.next;
    }
    while ((&node) != nullptr)
    {
        std::cout << node.val << " ";
    }
    std::cout << std::endl;
    return 0;
}