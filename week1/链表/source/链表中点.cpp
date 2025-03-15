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
void mid()//找中点
{
    struct node *temp1=head;//temp1是快指针，temp2是慢指针
    struct node *temp2=head;
    while(temp1->next!=NULL&&temp2!=NULL)
    {   //快指针一次走两步
        temp1=temp1->next;//快指针走第一步
        if(temp1->next!=NULL)
        {
            temp1=temp1->next;//快指针走第二步
        }
        temp2=temp2->next;//慢指针走一步
    }
    cout<<temp2->data;//快指针走到末尾，输出慢指针的值
}
int main()
{
    head=NULL;
    insect(2);//尾插数据，建立链表
    insect(6);
    insect(4);
    insect(5);
    insect(3);
    insect(7);
    insect(1);
    print();//打印链表
    printf("\n");//换行
    mid();//找中点
    return 0;
}