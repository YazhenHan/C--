#include <iostream>

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

int main()