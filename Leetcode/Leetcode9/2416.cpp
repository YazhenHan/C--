#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    struct node {
        node* nodes[26];
        bool flag;
        int children;
        node() {
            for (int i = 0; i < 26; i++)
                nodes[i] = nullptr;
            flag = false;
            children = 0;
        }
    };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        node* head = new node();
        for (const string & word : words) {
            node* temp = head;
            for (const char character : word) {
                if (temp->nodes[character - 'a'] == nullptr)
                    temp->nodes[character - 'a'] = new node();
                temp = temp->nodes[character - 'a'];
                temp->children++;
            }
            temp->flag = true;
        }
        
        vector<int> ans(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            node* temp = head;
            for (const char character : words[i]) {
                temp = temp->nodes[character - 'a'];
                ans[i] += temp->children;
            }
        }
        return ans;
    }
};