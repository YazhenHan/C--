#include <iostream>
#include <vector>
#include "../../Tools/Tools.hpp"

void exch(std::vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void selectSort(std::vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++)
    {
        int min = i;
        for (int j = i; j < N; j++)
            if (nums[j] < nums[min])
                min = j;
        exch(nums, i, min);
    }
}

void insertSort(std::vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++)
    {
        int j = i - 1, temp = nums[i];
        for (; j >= 0 && nums[j] > temp; j--)
            nums[j+1] = nums[j];
        nums[j+1] = temp;
    }
}

void shellSort(std::vector<int>& nums) {
    int N = nums.size();
    int h = 1;
    while (h < N / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < N; i++)
            for (int j = i; j >= h && nums[j] < nums[j-h]; j -= h)
                exch(nums, j, j-h);
        h = h / 3;
    }
}

int main() {
    std::vector<int> nums = {1,4,4,-2,3};
    insertSort(nums);
    std::cout << nums << std::endl;
    nums = {1,4,4,-2,3};
    selectSort(nums);
    std::cout << nums << std::endl;
    nums = {1,4,4,-2,3};
    shellSort(nums);
    std::cout << nums << std::endl;
    return 0;
}