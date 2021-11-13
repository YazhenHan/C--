#include <vector>
#include <unordered_set>

using namespace std;

struct HashFunc
{
	template<typename T, typename U>
	size_t operator()(const std::pair<T, U>& p) const {
		return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
	}
};

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_set<pair<int, int>, HashFunc> us;
        for (auto reservedSeat : reservedSeats)
            us.insert({reservedSeat[0] - 1, reservedSeat[1] - 1});
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int t = 2;
            if (us.find({i, 1}) != us.end() || us.find({i, 2}) != us.end()
             || us.find({i, 3}) != us.end() || us.find({i, 4}) != us.end())
                t--;
            if (us.find({i, 5}) != us.end() || us.find({i, 6}) != us.end()
             || us.find({i, 7}) != us.end() || us.find({i, 8}) != us.end())
                t--;
            if (t == 0 && us.find({i, 3}) == us.end() && us.find({i, 4}) == us.end()
             && us.find({i, 5}) == us.end() && us.find({i, 6}) == us.end())
                t++;
            ans += t;
        }
        return ans;
    }
};