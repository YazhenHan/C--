class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1 == nullptr && quadTree2 == nullptr) return nullptr;
        Node* ans = new Node();
        if (quadTree1->isLeaf && quadTree2->isLeaf) {
            ans->isLeaf = true;
            ans->val = quadTree1->val | quadTree2->val;
        } else if (!quadTree1->isLeaf && quadTree2->isLeaf) {
            ans->topLeft = intersect(quadTree1->topLeft, quadTree2);
            ans->topRight = intersect(quadTree1->topRight, quadTree2);
            ans->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2);
            ans->bottomRight = intersect(quadTree1->bottomRight, quadTree2);
            if (ans->topLeft->isLeaf && ans->topRight->isLeaf && ans->bottomLeft->isLeaf && ans->bottomRight->isLeaf && ans->topLeft->val == ans->topRight->val && ans->topRight->val == ans->bottomLeft->val && ans->bottomLeft->val == ans->bottomRight->val) {
                ans->isLeaf = true;
                ans->val = ans->topLeft->val;
                ans->topLeft = nullptr;
                ans->topRight = nullptr;
                ans->bottomLeft = nullptr;
                ans->bottomRight = nullptr;
            } else {
                ans->isLeaf = false;
            }
        } else if (quadTree1->isLeaf && !quadTree2->isLeaf) {
            ans->topLeft = intersect(quadTree1, quadTree2->topLeft);
            ans->topRight = intersect(quadTree1, quadTree2->topRight);
            ans->bottomLeft = intersect(quadTree1, quadTree2->bottomLeft);
            ans->bottomRight = intersect(quadTree1, quadTree2->bottomRight);
            if (ans->topLeft->isLeaf && ans->topRight->isLeaf && ans->bottomLeft->isLeaf && ans->bottomRight->isLeaf && ans->topLeft->val == ans->topRight->val && ans->topRight->val == ans->bottomLeft->val && ans->bottomLeft->val == ans->bottomRight->val) {
                ans->isLeaf = true;
                ans->val = ans->topLeft->val;
                ans->topLeft = nullptr;
                ans->topRight = nullptr;
                ans->bottomLeft = nullptr;
                ans->bottomRight = nullptr;
            } else {
                ans->isLeaf = false;
            }
        } else {
            ans->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            ans->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            ans->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            ans->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            if (ans->topLeft->isLeaf && ans->topRight->isLeaf && ans->bottomLeft->isLeaf && ans->bottomRight->isLeaf && ans->topLeft->val == ans->topRight->val && ans->topRight->val == ans->bottomLeft->val && ans->bottomLeft->val == ans->bottomRight->val) {
                ans->isLeaf = true;
                ans->val = ans->topLeft->val;
                ans->topLeft = nullptr;
                ans->topRight = nullptr;
                ans->bottomLeft = nullptr;
                ans->bottomRight = nullptr;
            } else {
                ans->isLeaf = false;
            }
        }
        return ans;
    }
};