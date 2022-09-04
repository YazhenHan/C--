#include <unordered_map>
#include <tuple>

using namespace std;

struct tuple_hash
{
	template <class T1, class T2, class T3>
	std::size_t operator() (const std::tuple<T1, T2, T3> &tuple) const
	{
		return std::hash<T1>()(get<0>(tuple)) ^ std::hash<T2>()(get<1>(tuple)) ^ std::hash<T3>()(get<2>(tuple));
	}
};

class Solution {
private:
    unordered_map<tuple<int, int, int>, int, tuple_hash> um;
    int dp(int startPos, int endPos, int k) {
        if (um.count({startPos, endPos, k})) return um[{startPos, endPos, k}];
        if (k < abs(endPos - startPos) || (k - abs(endPos - startPos)) % 2 != 0)
            return 0;
        if (k == abs(endPos - startPos)) return 1;
        long temp =  (dp(startPos - 1, endPos, k - 1) + dp(startPos + 1, endPos, k - 1)) % 1000000007;
        um.insert({{startPos, endPos, k}, temp});
        return temp;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        return dp(startPos, endPos, k);
    }
};