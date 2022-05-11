#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    string intostring(int val) {
        string s;
        int n = 0;
        while (val != 0) {
            s.push_back(val % 10 + 48);
            val /= 10;
            n++;
        }
        string ans;
        for (int i = 0; i < 5 - n; i++) {
            ans.push_back('0');
        }
        while (s.size() > 0) {
            ans.push_back(s.back());
            s.pop_back();
        }
        return ans;
    }

    int stringtoint(string s) {
        int val = 0;
        for (int i = 0; i < s.size(); i++) {
            val = val * 10 + s[i] - 48;
        }
        return val;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (root != NULL) {
            s += intostring(root->val);
            s += serialize(root->left);
            s += serialize(root->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        TreeNode* root = new TreeNode(stringtoint(data.substr(0, 5)));
        for (int i = 5; i < data.size(); i += 5) {
            int val = stringtoint(data.substr(i, 5));
            TreeNode* temp = root;
            while (temp != NULL)
            {
                if (temp->val > val) {
                    if (temp->left == NULL) {
                        temp->left = new TreeNode(val);
                        break;
                    }
                    temp = temp->left;
                }
                if (temp->val < val) {
                    if (temp->right == NULL) {
                        temp->right = new TreeNode(val);
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Codec c;
    cout << c.serialize(root) << endl;
    c.deserialize(c.serialize(root));
    return 0;
}