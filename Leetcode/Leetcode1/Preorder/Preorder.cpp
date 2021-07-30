#include<iostream>
#include<vector>
#include<queue>

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
    void preorder(Node* root, vector<int>& res) {
        if (root == nullptr)
        {
            return;
        }
        res.push_back(root->val);
        for(auto node : root->children) {
            preorder(node, res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    vector<int> preorder2(Node* root) {
        vector<int> res;
        queue<Node*> forRes;
        forRes.push(root);
        while (!forRes.empty())
        {
            Node* temp = forRes.front();
            forRes.pop();
            if (temp != nullptr)
            {
                res.push_back(temp->val);
                for(auto node : temp->children) {
                    forRes.push(node);
                }
            }
        }
        return res;
    }
};