#include <string>
#include <iostream>

template<typename Key, typename Value>
class BST
{
private:
    struct Node
    {
        Key key;
        Value val;
        Node *left = nullptr, *right = nullptr;
        int N;
        Node(Key key, Value val, int N) : key(key), val(val), N(N) {}
    };
    Node *root = nullptr;
    int size(Node *x) { if (x == nullptr) return 0; return x->N; }
    Value get(Node *x, Key key) {
        if (x == nullptr)
            return " ";
        if (x->key > key)
            return get(x->left, key);
        else if (x->key < key)
            return get(x->right, key);
        else
            return x->val;
    }
    Node* put(Node* x, Key key, Value val) {
        if (x == nullptr)
            return new Node(key, val, 1);
        if (x->key > key)
            x->left = put(x->left, key, val);
        else if (x->key < key)
            x->right = put(x->right, key, val);
        else
            x->val = val;
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
    Node* min(Node* x) {
        if (x->left == nullptr)
            return x;
        return min(x->left);
    }
    Node* select(Node *x, int k) {
        if (x == nullptr)
            return nullptr;
        int t = size(x->left);
        if (t > k)
            return select(x->left, k);
        else if (t < k)
            return select(x->right, k - t - 1);
        else
            return x;
    }
    Node* deleteMin(Node* x)
    {
        if (x->left == nullptr)
            return x->right;
        x->left = deleteMin(x->left);
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
    Node* deleteByKey(Node* x, Key key)
    {
        if (x == nullptr)
            return nullptr;
        if (x->key > key)
            x->left = deleteByKey(x->left, key);
        else if (x->key < key)
            x->right = deleteByKey(x->right, key);
        else
        {
            if (x->right == nullptr)
                return x->left;
            if (x->left == nullptr)
                return x->right;
            Node* t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->right;
        }
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
public:
    int size() { return size(root); }
    Value get(Key key) { return get(root, key); }
    void put(Key key, Value val) { root = put(root, key, val);}
    Key min() { return min(root)->key; }
    Key select(int k) { return select(root, k)->key; }
    void deleteMin() { root = deleteMin(root); }
    void deleteByKey(Key key) { root = deleteByKey(root, key); }
};

int main()
{
    BST<int, std::string>* bst = new BST<int, std::string>();
    bst->put(1, "a");
    bst->put(2, "b");
    bst->put(3, "d");
    bst->put(4, "c");
    bst->put(0, "b");
    std::cout << bst->get(1) << " " << bst->size() << std::endl;
    std::cout << bst->get(2) << " " << bst->size() << std::endl;
    std::cout << bst->get(3) << " " << bst->size() << std::endl;
    std::cout << bst->get(2) << " " << bst->size() << std::endl;
    std::cout << bst->get(0) << " " << bst->size() << std::endl;
    std::cout << bst->min() << " " << bst->size() << std::endl;
    bst->deleteMin();
    std::cout << bst->min() << " " << bst->size() << std::endl;
    bst->deleteByKey(3);
    std::cout << bst->min() << " " << bst->size() << std::endl;
    std::cout << bst->select(0) << " " << bst->size() << std::endl;
    return 0;
}
