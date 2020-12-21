#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main()
{
    int N;
    scanf("%d", &N);

    // 第一问
    struct node *head = NULL, *head2 = NULL;     // head永远指向头节点
    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        struct node* tempNode = malloc(sizeof(struct node));   // 新建节点
        tempNode->data = temp;
        tempNode->next = NULL;
        if (head2 == NULL)       // 代表是头节点
        {
            head2 = tempNode;
            head = head2;        // 让head指向头节点
        }
        else
        {
            head2->next = tempNode;
            head2 = head2->next;     // head2指向尾节点，每次插入都在head2之后插入
        }
    }
    // 结束第一问

    // 第二问
    int minNum = INT_MAX;    // 最小值
    head2 = head;
    int cur = 0;             // 最小值所在位置
    for (int i = 0; head2 != NULL; i++)     // 找到最小的节点位置
    {
        if (head2->data < minNum)
        {
            minNum = head2->data;
            cur = i;
        }
        head2 = head2->next;
    }
    
    head2 = head;
    for (int i = 0; i < cur; i++)     // 定位到最小节点位置
        head2 = head2->next;
    
    if (head2->data % 2 != 0)         // 奇数
    {
        if (head2->next == NULL)
            return 0;
        head2->data = head2->next->data;    // 交换当前节点和之后节点的值
        head2->next->data = minNum;
    }
    else                              // 偶数
    {
        if (head2->next == NULL)
            return 0;
        struct node *tempNode = head2->next;
        head2->next = tempNode->next;       // 删除之后一个节点
        free(tempNode);                     // 释放存储空间
    }
    // 第二问结束


    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    
    return 0;
}