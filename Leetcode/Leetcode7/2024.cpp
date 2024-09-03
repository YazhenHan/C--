#include <string>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0, right = 0, tn = 0, fn = 0, ans = 0;
        answerKey[0] == 'T' ? tn++ : fn++;
        while (right < answerKey.size()) {
            if (tn <= k || fn <= k) {
                right++;
                answerKey[right] == 'T' ? tn++ : fn++;
            } else {
                answerKey[left] == 'T' ? tn-- : fn--;
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};