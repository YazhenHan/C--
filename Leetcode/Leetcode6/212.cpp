#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


// Out of time.
class Solution {
private:
    unordered_set<string> ans;
    struct node
    {
        bool flag;
        node* nodes[26];
        node() {
            flag = false;
            for (auto & node : nodes)
                node = nullptr;
        }
    };
    void dfs(int i, int j, const vector<vector<char>>& board, node * root, string temp, vector<vector<bool>> & flags) {
        if (root->flag)
            ans.insert(temp);
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || flags[i][j] || root->nodes[board[i][j] - 'a'] == nullptr)
            return;
        temp.push_back(board[i][j]);
        flags[i][j] = true;
        dfs(i + 1, j, board, root->nodes[board[i][j] - 'a'], temp, flags);
        dfs(i - 1, j, board, root->nodes[board[i][j] - 'a'], temp, flags);
        dfs(i, j + 1, board, root->nodes[board[i][j] - 'a'], temp, flags);
        dfs(i, j - 1, board, root->nodes[board[i][j] - 'a'], temp, flags);
        flags[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* root = new node();
        for (auto& word : words) {
            node * temp = root;
            for (auto c : word) {
                if (temp->nodes[c - 'a'] == nullptr)
                    temp->nodes[c - 'a'] = new node();
                temp = temp->nodes[c - 'a'];
            }
            temp->flag = true;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                vector<vector<bool>> flags(board.size(), vector<bool>(board[i].size(), false));
                dfs(i, j, board, root, "", flags);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};


class Solution {
private:
    unordered_set<string> ans;
    struct node
    {
        bool flag;
        node* nodes[26];
        node() {
            flag = false;
            for (auto & node : nodes)
                node = nullptr;
        }
    };
    void dfs(int i, int j, const vector<vector<char>>& board, node * root, string temp, vector<vector<bool>> & flags) {
        if (root->nodes[board[i][j] - 'a'] == nullptr)
            return;
        temp.push_back(board[i][j]);
        if (root->nodes[board[i][j] - 'a']->flag)
            ans.insert(temp);
        flags[i][j] = true;
        if (i + 1 < board.size() && !flags[i + 1][j])
            dfs(i + 1, j, board, root->nodes[board[i][j] - 'a'], temp, flags);
        if (i - 1 >= 0 && !flags[i - 1][j])
            dfs(i - 1, j, board, root->nodes[board[i][j] - 'a'], temp, flags);
        if (j + 1 < board[i].size() && !flags[i][j + 1])
            dfs(i, j + 1, board, root->nodes[board[i][j] - 'a'], temp, flags);
        if (j - 1 >= 0 && !flags[i][j - 1])
            dfs(i, j - 1, board, root->nodes[board[i][j] - 'a'], temp, flags);
        flags[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* root = new node();
        for (auto& word : words) {
            node * temp = root;
            for (auto c : word) {
                if (temp->nodes[c - 'a'] == nullptr)
                    temp->nodes[c - 'a'] = new node();
                temp = temp->nodes[c - 'a'];
            }
            temp->flag = true;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                vector<vector<bool>> flags(board.size(), vector<bool>(board[i].size(), false));
                dfs(i, j, board, root, "", flags);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};