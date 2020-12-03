class Solution
{
public:
    int countPrimes(int n)
    {
        int *p = (int *)malloc(n * sizeof(int));
        memset(p, 0, n * sizeof(int));
        int res = 0;
        for (int i = 2; i < n; i++)
        {
            if (!p[i])
            {
                for (int j = 2; i * j < n; j++)
                    p[i * j] = 1;
                res++;
            }
        }
        return res;
    }
};