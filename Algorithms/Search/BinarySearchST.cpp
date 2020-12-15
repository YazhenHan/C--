#include <vector>
#include <string>
#include <iostream>

template <typename T, typename U>
class BinarySearchST
{
private:
    std::vector<T> keys;
    std::vector<U> vals;
    int N = 0;
public:
    int rank(T key) {
        int lo = 0, hi = N - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (key < keys[mid])
                hi = mid - 1;
            else if (key > keys[mid])
                lo = mid + 1;
            else
                return mid;
        }
        return lo;
    }
    U get(T key) {
        int i = rank(key);
        if (i < N && keys[i] == key)
            return vals[i];
        return 0;
    }
    void put(T key, U val) {
        int i = rank(key);
        if (i < N && keys[i] == key)
        {
            vals[i] = val;
            return;
        }
        keys.resize(N + 1);
        vals.resize(N + 1);
        for (int j = N; j > i; j--)
        {
            keys[j] = keys[j-1];
            vals[j] = vals[j-1];
        }
        keys[i] = key;
        vals[i] = val;
        N++;
    }
};

int main() {
    BinarySearchST<std::string, int> st;
    st.put("1", 300);
    std::cout << st.get("1") << std::endl;
    st.put("2", 500);
    std::cout << st.get("2") << std::endl;
    st.put("1", 600);
    std::cout << st.get("1") << std::endl;
    return 0;
}