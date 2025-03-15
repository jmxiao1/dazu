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
void isloop()//判断链表是否成环
{
    struct node *slow=head;//两指针，一个快，一个慢
    struct node *fast=head;
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;//慢指针一次走一步
        fast=fast->next;//快指针一次走两步
        fast=fast->next;
    
    if(slow==fast)//如果快指针追上慢指针，说明有环
    {
        cout<<"It's a loop"<<endl;
        return;
    }
    }
    cout<<"It's not a loop"<<endl;//如果能跳出循环，则证明无环
}
int main()
{
    head=NULL;
    insect(2);//尾插数据，建立链表1
    insect(6);
    insect(4);
    insect(5);
    insect(3);
    insect(7);
    insect(1);
    print();//打印链表
    printf("\n");//换行
    isloop();//判断链表是否成环
    struct node *temp=head;//开始建环
    while(temp->next!=NULL)
    {
        temp=temp->next;//找到链表2的最后一个节点
    }
    temp->next=head;//将链表2的最后一个节点指向链表1的头节点，形成环
    isloop();//判断链表是否成环*/
    return 0;
}