#include <iostream>
using namespace std;//前面和双向链表内容一样就不多写注释了（
struct node {
    int data;
    struct node *next;
    struct node *prev;
}; //惯例结构体                                                                 
struct node *head;//头节点
void print()//打印
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insect(int n)//插入
{
    struct node *temp1= new struct node;
    temp1->data=n;
    temp1->next=NULL;
    temp1->prev=NULL;
    if (head==NULL)
    {
        head=temp1;
        return;
    }
    struct node *temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;

    }
    temp2->next=temp1;
    temp1->prev=temp2;
}
void reverse1()//链表反转，这段运用迭代，用三个指针，反复移动位置进行交换实现反转
{
    // 定义三个指针，prev指向NULL，current指向当前节点，next也暂时指向空
    struct node *prev=NULL;
    struct node *current=head;
    struct node *next=NULL;
    // 当current不为空时，循环执行以下操作
    while(current!=NULL)
    {
        // 将next指向current的下一个节点
        next=current->next;                                
        // 将current的next指向prev，实现链表的反转        
        current->next=prev;                      
        // 将prev指向current，实现prev的移动
        prev=current;
        // 将current指向next，实现current的移动
        current=next;
    }
    // 将head指向prev，实现链表的反转
    head=prev;
}
void reverse2(struct node *p)//递归实现链表反转,思路是先反转后面的节点，再反转当前节点,但
{
    if(p->next==NULL)//为尾节点时，作为头节点直接返回
    {head=p;
    return;
    }
    reverse2(p->next);//递归反转后面的节点
    struct node *q=p->next;//反转完后面节点后，反转该节点，
    q->next=p;//反转
    p->prev=q;
    p->next=NULL; //注意，这里一定要将当前节点的next置为NULL，否则会形成环
}
int main()
{
    head=NULL;

        insect(2);//建立链表，就不多讲了
        insect(6);
        insect(4);
        insect(5);
        insect(3);
        insect(1);
        insect(7);
        print();//原始链表打印
        printf("\n");
        reverse1();//迭代反转
        print();
        printf("\n");
        reverse2(head);//递归反转
        print();
        printf("\n");
        return 0;
}