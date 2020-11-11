#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int>& A) {
    for (int j = 1; j < A.size(); j++)
    {
        int key = A[j];
        //Insert A[j] into the sorted sequence A[0...j-1]
        int i = j - 1;
        while (i >= 0 && A[i] < key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

int main() {
    vector<int> A;
    int temp;
    while (cin >> temp)
    {
        A.push_back(temp);
    }
    insertionSort(A);
    for (auto &a : A)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}