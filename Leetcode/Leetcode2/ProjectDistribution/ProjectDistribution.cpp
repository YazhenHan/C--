#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> forAns(M, 0);
    int ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            int temp;
            std::cin >> temp;
            if (temp > forAns[j])
            {
                ans += (temp - forAns[j]);
                forAns[j] = temp;
            }
        }
    }
    std::cout << ans;
    return 0;
}