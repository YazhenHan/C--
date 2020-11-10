#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int count = 0;
    for(int i = s.size() - 1, j = g.size() - 1;i >= 0 && j >= 0;j--) {
        if (s[i] >= g[j])
        {
            count++;
            i--;
        }
    }
    return count;
}

int main() {
    vector<int> g = {1,2};
    vector<int> s = {};
    cout << findContentChildren(g, s) << endl;
    return 0;
}