class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        bool flag = false;
        Node* ans = head;
        do {
            if (head->val <= insertVal && head->next->val >= insertVal) {
                flag = true;
                break;
            }
            head = head->next;
        } while (head != ans);
        if (flag) {
            Node* temp = new Node(insertVal);
            temp->next = head->next;
            head->next = temp;
            return ans;
        }
        head = ans;
        flag = false;
        do {
            if (head->val != head->next->val)
                flag = true;
            head = head->next;
        } while (head != ans);
        head = ans;
        if (flag) {
            do {
                if ((head->val >= insertVal && head->val > head->next->val && head->next->val >= insertVal) || (head->val <= insertVal && head->val > head->next->val && head->next->val <= insertVal))
                    break;
                    head = head->next;
            } while (head != ans);
        } else {
            do {
                if ((head->val >= insertVal && head->val >= head->next->val && head->next->val >= insertVal) || (head->val <= insertVal && head->val >= head->next->val && head->next->val <= insertVal))
                    break;
                    head = head->next;
            } while (head != ans);
        }
        Node* temp = new Node(insertVal);
        temp->next = head->next;
        head->next = temp;
        return ans;
    }
};