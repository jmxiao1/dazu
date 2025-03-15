#include <iostream>
using namespace std;

struct Node//定义节点
{
    int data;
    Node *next;//指向下一个节点
    Node *prev;//指向前一个节点
};
struct Node *head=NULL;
void insert(int data)
{
    // 创建一个新节点，并分配内存空间
    struct Node *p = new Node;
    // 传入数据
    p->data = data;
    // 将新节点的next指针赋值为NULL
    p->next = NULL;
    // 将新节点的prev指针赋值为NULL
    p->prev = NULL;
    if (head == NULL)
    {
        // 如果头节点的next指针指向NULL，则将新节点插入到链表中
        head=p;
        return;
    }
    if(head->next==NULL)
    {
        head->next=p;
        p->prev=head;
        return;
    }
    else
    {   struct Node *q = head->next;
        while(q->next!=NULL)//找到最后一个节点
        {
            q=q->next;
        }
        p->prev= q;
        q->next = p;
    }

}
void print(Node *head)// 打印链表,基本操作和单向链表一样
{
    // 创建一个指针p，指向头节点
    Node *p = head;
    // 如果p指针指向NULL，则退出循环
    while (p != NULL)
    {
        // 输出p指针指向的节点的数据
        cout << p->data << " ";
        // 将p指针指向下一个节点
        p = p->next;
    }
}
void de(int n)//删除第n个节点,和单向链表一样,但是要处理反向
{   struct Node *temp1=head;//创建一个指针指向头节点
    if (n==1)//删除头节点
    {
        head=temp1->next;
        return;
    }
    for(int i=0;i<n-2;i++)//找到第n-1个节点
    {
        temp1=temp1->next;
    }
    if(temp1->next->next==NULL)//删除最后一个节点
    {
        temp1->next=NULL;
        return;
    }
    struct Node *temp2=temp1->next;
    struct Node *temp3=temp2->next;//多了这个
    temp1->next=temp2->next;
    temp3->prev=temp1;//多了这个
    delete temp2;
}
    
int main()
{
    insert(2);//插入节点
    insert(6);
    insert(3);
    insert(7);
    insert(5);
    insert(4);
    insert(1);
    print(head);//打印
    printf("\n");
    printf("enter the numbers of nodes to be delected\n");//删除节点
    int n;
    cin >> n;   
    de(n);
    print(head);//打印
    return 0;
}