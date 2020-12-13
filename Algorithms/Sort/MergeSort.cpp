#include <vector>
#include <iostream>
#include "../../Tools/Tools.hpp"

class MergeSort
{
private:
    std::vector<int> aux;
    void sort(std::vector<int>& a, int lo, int hi);
    void merge(std::vector<int>& a, int lo, int mid, int hi);
public:
    void MergeUB(std::vector<int>& a);
    void MergeBU(std::vector<int>& a);
    ~MergeSort();
};

void MergeSort::MergeBU(std::vector<int>& a)
{
    int N = a.size();
    aux.resize(N);
    for (int sz = 1; sz < N; sz = sz + sz)
        for (int lo = 0; lo < N - sz; lo += sz + sz)
            merge(a, lo, lo + sz - 1, std::min(lo + sz + sz - 1, N - 1));
}

void MergeSort::MergeUB(std::vector<int>& a)
{
    aux.resize(a.size());
    sort(a, 0, a.size() - 1);
}

void MergeSort::sort(std::vector<int>& a, int lo, int hi)
{
    if (hi <= lo)
        return;
    int mid = lo + (hi - lo) / 2;
    sort(a, lo, mid);
    sort(a, mid + 1, hi);
    merge(a, lo, mid, hi);
}

void MergeSort::merge(std::vector<int>& a, int lo, int mid, int hi)
{
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k];
    for (int k = lo; k <= hi; k++)
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (aux[j] < aux[i])
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
}

MergeSort::~MergeSort()
{
}

int main()
{
    std::vector<int> nums = {1,4,4,-2,3};
    MergeSort ms;
    ms.MergeUB(nums);
    std::cout << nums << std::endl;
    return 0;
}