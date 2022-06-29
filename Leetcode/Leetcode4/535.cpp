#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, string> um;
    int q;
public:
    Solution() {
        q = 0;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        q++;
        um.insert({q, longUrl});
        return "http://tinyurl.com/" + to_string(q);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int p = shortUrl.rfind('/') + 1;
        int key = stoi(shortUrl.substr(p, shortUrl.size() - p));
        return um[key];
    }
};