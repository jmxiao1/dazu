#include <iostream>
using namespace std;
const int maxsize = 100;
// 定义一个结构体
struct node {
    int data;
    node *next;
};
// 定义一个指向结构体的指针，作为栈顶指针
struct node*top=NULL;
// 入栈操作，将元素x压入栈顶
void push(int x) {
    node *p = new node;//创建一个新节点
    p->data = x;
    p->next = top;
    top = p;
}
// 出栈操作，将栈顶元素弹出
// 弹出栈顶元素
void pop() {
    // 指向栈顶元素的指针
    node *p = top;
    // 栈顶指针指向下一个元素
    top = top->next;
    // 释放内存
    delete p;
}
// 返回栈顶元素
int Top() {
    return top->data;
}
// 判断栈是否为空
bool empty() {
    return top == NULL;
}
// 递归打印链表
void print(struct node *p)
{
    if (p == NULL)
    {
    return;
    }
    print (p->next);//递归
    cout << p->data << " ";
    return;
}
// 循环打印链表
void stackprint()
{
    node *p = top;
    while (p != NULL){
   cout << p->data << " ";//循环
   p = p->next;}
    cout << endl;
}
int main() {
    int choice;int x;
    while(1)
    {
        printf("***************************************************\n");
        printf("**********       1.入栈                  **********\n");
        printf("**********       2.出栈                  **********\n");
        printf("**********       3.返回栈顶元素           **********\n");
        printf("**********       4.判断栈是否为空         **********\n");
        printf("**********       5.递归打印链表           **********\n");
        printf("**********       6.循环打印链表           **********\n");
        printf("**********       7.退出                  **********\n");
        printf("***************************************************\n");
        printf("请输入你的选择：");
        scanf("%d",&choice);
        switch(choice)
        {
            
            case 1:printf("请输入要入栈的数字："); scanf("%d",&x);push(x);break;
            case 2:pop();break;
            case 3:if(!empty()){printf("%d",Top());}else{printf("栈为空！");}printf("\n");break;
            case 4:if(empty()){printf("栈为空！");}else{printf("栈不为空！");}printf("\n");break;
            case 5:print(top);printf("\n");break;
            case 6:stackprint();printf("\n");break;
            case 7:exit(0);break;

        }
    }
    return 0;
}
