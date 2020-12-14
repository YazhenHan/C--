#include <vector>
#include <iostream>
#include "../../Tools/Tools.hpp"

class QuickSort
{
private:
    void sort(std::vector<int>& a, int lo, int hi);
    int partition(std::vector<int>& a, int lo, int hi);
    void exch(std::vector<int>& a, int i, int j);
public:
    void sort(std::vector<int>& a);
};

void QuickSort::sort(std::vector<int>& a)
{
    sort(a, 0, a.size() - 1);
}

void QuickSort::sort(std::vector<int>& a, int lo, int hi)
{
    if (hi <= lo)
        return;
    int j = partition(a, lo, hi);
    sort(a, lo, j - 1);
    sort(a, j + 1, hi);
}

int QuickSort::partition(std::vector<int>& a, int lo, int hi)
{
    int i = lo, j = hi + 1;
    int v = a[lo];
    while (true)
    {
        while (a[++i] < v)
            if (i == hi)
                break;
        while (v < a[--j])
            if (j == lo)
                break;
        if (i >= j)
            break;
        exch(a, i, j);
    }
    exch(a, lo, j);
    return j;
}

void QuickSort::exch(std::vector<int>& a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main()
{
    std::vector<int> nums = {1,4,4,-2,3};
    QuickSort qs;
    qs.sort(nums);
    std::cout << nums << std::endl;
    return 0;
}