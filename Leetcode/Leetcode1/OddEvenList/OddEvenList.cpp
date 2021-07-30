#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* odList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return nullptr;
        } else {
            head->next = odList(head->next->next->next);
            return head;
        }
    }

    // ListNode* oddEvenList(ListNode* head) {
    //     ListNode* res = odList(head);
    //     ListNode* temp = odList(head->next);
    //     while (res->next != nullptr)
    //     {
    //         res = res->next;
    //     }
    //     res->next = temp;
    //     return res;
    // }
    
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* headNext = head->next;
        ListNode* res = head;
        ListNode* forRes = headNext;
        while (headNext != nullptr)
        {
            head->next = headNext->next;
            if (head->next != nullptr)
            {
                head = head->next;
            }
            headNext->next = head->next;
            headNext = headNext->next;
        }
        head->next = forRes;
        return res;
    }
};

int main() {
    int temp;
    cin >> temp;
    ListNode* head = new ListNode(temp);
    ListNode* rhead = head;
    while (cin >> temp)
    {
        ListNode* tempNode = new ListNode(temp);
        head->next = tempNode;
        head = head->next;
    }
    cout << sizeof(ListNode) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(ListNode*) << endl;
    head->next = nullptr;
    while (rhead != nullptr)
    {
        cout << rhead << " ";
        cout << rhead->val << " ";
        rhead = rhead->next;
    }
    cout << endl;
    return 0;
}