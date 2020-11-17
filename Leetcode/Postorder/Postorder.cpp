#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void postorder(Node* root, vector<int>& res) {
        if (root == nullptr)
        {
            return;
        }
        for(auto node : root->children) {
            postorder(node, res);
            res.push_back(node->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};