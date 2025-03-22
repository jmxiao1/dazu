#include <iostream>
using namespace std;///和另一边一样
const int maxsize = 100;
struct node {
    int data;
    node *next;
};
struct node*top=NULL;
void push(int x) {
    node *p = new node;
    p->data = x;
    p->next = top;
    top = p;
}
void pop() {
    node *p = top;
    top = top->next;
    delete p;
}
int Top() {
    return top->data;
}
bool empty() {
    return top == NULL;
}
void print(struct node *p)
{
    if (p == NULL)
    {
    return;
    }
    print (p->next);
    cout << p->data << " ";
    return;
}
void stackprint()
{
    node *p = top;
    while (p != NULL){
   cout << p->data << " ";
   p = p->next;}
    cout << endl;
}
bool isopeningparentnesess(char op) {//判断是否为左括号
    
    if (op == '(') {
        return true;
    }
    else {
        return false;
    }
}
bool hashigherpre(char op1, char op2) {//判断操作符优先级
    if (op1 == '*' || op1 == '/') {//乘除肯定比加减优先
        if (op2 == '+' || op2 == '-') {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
void infixtopostfix(char *infix, char *postfix) {//中缀转后缀
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (infix[i]!='+'&& infix[i] != '-'&& infix[i] != '*'&& infix[i] != '/') {
            postfix[j++] = infix[i];//数字直接放入字符串
        }
        else if(infix[i]=='+'|| infix[i] == '-'|| infix[i] == '*'|| infix[i] == '/')
        {
            while (!empty() && hashigherpre(Top(),infix[i])&&!isopeningparentnesess(Top())) {
                postfix[j++] = Top();//运算符判断后放入字符串
                pop();
            }
            push(infix[i]); //将运算符放入栈中
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!empty() && !isopeningparentnesess(Top()))
            {
                postfix[j++] = Top();//将左括号内的运算符放入后缀表达式
                pop();
            }
            pop(); //将左括号弹出
        }
        i++;
    } //将栈中剩余的运算符放入后缀表达式中
    while(!empty()) {
    postfix[j++] = Top();
    pop();

    }
                
 }
//后缀表达式求值
void evaluatepostfix(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i]!='+'&& s[i] != '-'&& s[i] != '*'&& s[i] != '/') //只要数字
        {
            push(s[i] - '0');//将字符转化为数字，放入栈中
            cout<<s[i]<<" ";
        }
        else {//读到运算符
            int OP2 = Top();//拿出两个数进行计算
            pop();
            int OP1 = Top();
            pop();
            switch (s[i]) {
        
                case '+':push(OP1 +OP2 ); break;//加
                case '-':push(OP1-OP2); break;//减
                case '*':push(OP1 * OP2); break;//乘
                case '/':push(OP1/ OP2); break;//除
            }
        }
        i++;//指针后移

    }

} 
int main() {
    char infix[maxsize];
    char postfix[maxsize];
    cout << "请输入算式：";
    cin >> infix;
    infixtopostfix(infix, postfix);//中缀转后缀
    evaluatepostfix(postfix);//后缀求值
    cout << "结果为：";
    cout << Top() << endl;//   输出答案
}