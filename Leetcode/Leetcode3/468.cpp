#include <string>

using namespace std;

class Solution {
private:
    bool isIpv4(string ipv4) {
        if (ipv4.size() < 1 || ipv4.size() > 3 || ipv4.size() > 1 && ipv4[0] == '0') return false;
        int ans = 0;
        for (int i = 0; i < ipv4.size(); i++) {
            if (!(ipv4[i] >= 48 && ipv4[i] <= 57)) return false;
            ans = ans * 10 + (ipv4[i] - '0');
        }
        return ans <= 255;
    }
    bool isIpv6(string ipv6) {
        if (ipv6.size() > 4 || ipv6.size() < 1) return false;
        for (int i = 0; i < ipv6.size(); i++) {
            if (!(ipv6[i] >= 48 && ipv6[i] <= 57 || ipv6[i] >= 65 && ipv6[i] <= 70 || ipv6[i] >= 97 && ipv6[i] <= 102)) return false;
        }
        return true;
    }
public:
    string validIPAddress(string queryIP) {
        int flag = 0;
        for (int i = 0; i < queryIP.size(); i++) {
            if (queryIP[i] == '.')
                flag = 1;
            else if (queryIP[i] == ':')
                flag = 2;
        }
        if (!flag) return "Neither";
        if (flag == 1) {
            int left = 0, num = 0;
            if (queryIP.front() == '.' || queryIP.back() == '.') return "Neither";
            for (int i = 0; i < queryIP.size(); i++) {
                if (queryIP[i] == '.') {
                    if (!isIpv4(queryIP.substr(left, i - left))) return "Neither";
                    left = i + 1;
                    num++;
                } else if (i == queryIP.size() - 1) {
                    if (!isIpv4(queryIP.substr(left, i - left + 1))) return "Neither";
                }
            }
            return num == 3 ? "IPv4" : "Neither";
        } else {
            int left = 0, num = 0;
            if (queryIP.front() == ':' || queryIP.back() == ':') return "Neither";
            for (int i = 0; i < queryIP.size(); i++) {
                if (queryIP[i] == ':') {
                    if (!isIpv6(queryIP.substr(left, i - left))) return "Neither";
                    left = i + 1;
                    num++;
                } else if (i == queryIP.size() - 1) {
                    if (!isIpv6(queryIP.substr(left, i - left + 1))) return "Neither";
                }
            }
            return num == 7 ? "IPv6" : "Neither";
        }
    }
};