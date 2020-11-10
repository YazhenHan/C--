#include<iostream>
#include<vector>

long long F(int N) {
    if (N == 0)
    {
        return 0;
    }
    if (N == 1)
    {
        return 1;
    }
    return F(N - 1) + F(N - 2);
}

long long NewF(int N, std::vector<long long>& nums) {
    if (N == 0 || N == 1 || nums[N] != 0)
    {
        return nums[N];
    }
    return nums[N] = NewF(N - 1, nums) + NewF(N - 2, nums);
}

int main() {
    std::vector<long long> nums(100, 0);
    nums[1] = 1;
    for (int i = 0; i < 100; i++)
    {
        std::cout << NewF(i, nums) << " ";
        if ((i + 1) % 10 == 0)
        {
            std::cout << std::endl;
        }
    }
}