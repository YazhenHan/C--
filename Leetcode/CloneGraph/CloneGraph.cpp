#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*,Node*> filter;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return node;
        if (filter.find(node) != filter.end())
            return filter[node];
        Node *head = new Node(node->val);
        filter[node] = head;
        for (auto& neighbor : node->neighbors)
            head->neighbors.push_back(cloneGraph(neighbor));
        return head;
    }
};