#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
struct node {
    int data;                                                                 //存储节点数据
    struct node *next;                                                        //定义指针，指向下一个节点
};                                                            
struct node *head;
void insect(int n)//尾插法生成链表
{
    // 创建一个新的节点，并将数据n赋值给该节点的data域
    struct node *temp1= new struct node;
    temp1->data=n;
    temp1->next=NULL;
    // 如果链表为空，则将新节点赋值给头节点
    if (head==NULL)
    {
        head=temp1;
        return;
    }
    // 否则，遍历链表，找到最后一个节点
    struct node *temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;

    }
    // 完成插入
    temp2->next=temp1;
}

void print()//打印链表
{
    // 定义一个指向链表头节点的指针temp
    struct node *temp=head;
    // 当temp指针不为空时，循环执行以下操作
    while(temp!=NULL)
    {
        // 输出temp指针指向的节点的数据
        cout<<temp->data<<" ";
        // 将temp指针指向下一个节点
        temp=temp->next;
    }
}
void de(int n)
{  struct node *temp1=head;//定义一个指针temp1，指向头节点
    if (n==1)//如果删除头节点
    {
        head=temp1->next;
        return;
    }
    for(int i=0;i<n-2;i++)//找到第n-1个节点
    {
        temp1=temp1->next;
    }
struct node *temp2=temp1->next;//定义一个指针temp2，指向第n个节点
    temp1->next=temp2->next;//将第n-1个节点的指针域指向第n+1个节点
    delete temp2;//释放第n个节点的内存空间，即删除该节点
}
void insect1(int number,int n)//插入节点,n为插入位置,number为插入数据
{
    //创建新节点
    struct node *temp1= new struct node;
    temp1->data=number;
    temp1->next=NULL;
    //如果插入位置为1，则将新节点插入到链表头部
    if (n==1)
    {
    temp1->next=head;
    head=temp1;
    return;
    }
    //否则，找到插入位置的前一个节点
    struct node *temp2=head;
    for(int i=0;i<n-2;i++)
    {
        temp2=temp2->next;
    }
    //将新节点插入到链表中
    temp1->next=temp2->next;
    temp2->next=temp1;
}
int main()
{int n,data,locate;
head=NULL;
insect(2);//尾插数据，建立链表
insect(6);
insect(4);
insect(5);
insect(3);
insect(7);
print();//打印链表
printf("\n");
printf("enter the number of nodes to be deleted\n");
scanf("%d",&n);
de(n);//删除节点n
print();
printf("\n");
printf("enter the number of nodes and data to be insect\n");
scanf("%d %d",&data,&locate);
insect1(data,locate);//插入节点
print();
return 0;
}