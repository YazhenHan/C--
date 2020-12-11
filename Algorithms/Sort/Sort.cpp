#include <cstdlib>
#include <iostream>

template<class T>
class Sort
{
public:
    T* a;
public:
    Sort(int size) {
        a = (T*)malloc(size * sizeof(T));
    }
    ~Sort() {
        free(a);
    }
};

int main() {
    Sort<int> a = Sort<int>(5);
    for (int i = 0; i < 5; i++)
    {
        a.a[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << a.a[i] << " ";
    }
    return 0;
}