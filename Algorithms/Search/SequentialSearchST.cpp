#include <string>
#include <iostream>

template <typename T, typename U>
class SequentialSearchST
{
private:
    struct node
    {
        T key;
        U val;
        node* next = nullptr;
        node(T key, U val, node* next) : key(key), val(val), next(next) {}
    };
    node* first = nullptr;
public:
    void put(T key, U val) {
        for (node* x = first; x != nullptr; x++)
            if (x->key == key)
            {
                x->val = val;
                return;
            }
        first = new node(key, val, first);
    }
    U get(T key) {
        for (node* x = first; x != nullptr; x = x->next)
            if (x->key == key)
                return x->val;
        return 0;
    }
};

int main() {
    SequentialSearchST<std::string, int> st;
    std::cout << st.get("abc") << std::endl;
    st.put("abc", 300);
    std::cout << st.get("abc") << std::endl;
    return 0;
}