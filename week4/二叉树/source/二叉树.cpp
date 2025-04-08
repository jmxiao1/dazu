#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct bstnode//定义二叉树节点
{
    int data;
    bstnode *left, *right;
};
//bstnode *root = NULL;//全局变量//
bstnode*getnewnode(int data)
{
    bstnode *newnode = new bstnode;
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
bstnode*insert(bstnode *root, int data)//插入功能
{
    // 如果根节点为空，则创建一个新节点，并将其赋值给根节点
    if (root == NULL)
    {
        root = getnewnode(data);
        return root;
    }
    // 如果插入的数据小于根节点的数据，则调用函数，传入根节点的左子节点
    else if (data <=root->data)
    {
        root->left = insert(root->left, data);
    }
    // 如果插入的数据大于根节点的数据，则调用函数，传入根节点的右子节点
    else
    {
        root->right = insert(root->right, data);
    }

    // 返回根节点
    return root;
}
struct bstnode*find(bstnode *root, int data)//查找功能
{
    if (root == NULL)//如果树为空，返回空
    {
        return NULL;
    }
    else if (data == root->data)
    {
        return root;//如果找到，返回该节点
    }
    else if (data < root->data)
    {
        return find(root->left, data);//如果小于，递归从左查找
    }
    else
    {
        return find(root->right, data);//同理，如果大于，就递归从右查找
    }
}
bool search(bstnode *root, int data)//布尔函数查找，返回是否找到，而不是返回节点
{   if (root == NULL)
    {
        return false;
    }
    else if (data == root->data)
    {
        return true;
    }
    else if (data < root->data)
    {
        search(root->left, data);
    }
    else
    {
        search(root->right, data);
    }
    return false;
}
 /*void min(bstnode *root)  //输出最小节点                          
  {
    // 如果根节点为空，则输出"empty tree"
    if (root == NULL)
    {
        cout << "empty tree" << endl;
    }
    // 如果根节点的左子节点为空，则输出根节点的数据
    else if (root->left == NULL)
    {
        cout << root->data << endl;
    }
    // 否则，递归调用min函数，传入根节点的左子节点
    else
    {
        min(root->left);
    }
}*/
struct bstnode* findmin(bstnode *root)
{   //min 与findmin的区别在于min是函数，findmin是函数体,但是二者都可以实现 相同的功能
    while (root->left != NULL)
    {
       root = root->left;
    }
    cout << root->data << endl;
    return root;
}
/*void max(bstnode *root)//输出最大节点
{
    // 如果根节点为空，则输出"empty tree"
    if (root == NULL)
    {
    
 cout << "empty tree" << endl;}
    // 如果根节点的右子节点为空，则输出根节点的数据
    else if(root->right==NULL)
    {
        cout << root->data << endl;

    }
    // 否则，递归调用max函数，传入根节点的右子节点
    else{ max(root->right);}
}*/
struct bstnode* findmax(bstnode *root)
{    //max 与findmax的区别在于max是函数，findmax是函数体,但是二者都可以实现相同的功能
    while (root->right != NULL)
    {
        root = root->right;
    }
    cout << root->data << endl;
    return root;
}
int findheight(bstnode *root)//计算节点最大高度
{
    if (root == NULL)
    {
        return -1;//空则返回-1
    }
    else
   {
    return max(findheight(root->left), findheight(root->right)) + 1;//调用递归
  }
   
    }
    void levelorder(bstnode *root)//层序遍历，广度优先遍历
    {
        // 如果根节点为空，则直接返回
        if (root == NULL)
        {
            return;
        }
        // 创建一个队列，用于存储二叉树的节点
        queue<bstnode *> q;
        // 将根节点入队
        q.push(root);
        // 当队列不为空时，循环执行
        while (!q.empty())
        {
            // 取出队列中的第一个节点
            bstnode *current = q.front();
            // 输出该节点的值
            cout << current->data << " ";
            // 如果该节点有左子节点，则将左子节点入队
            if (current->left != NULL)
            {
                q.push(current->left);}
            if (current->right != NULL)
            {
                q.push(current->right);

            }
            q.pop();
    }
    cout << endl;}
/*bool isbstlesser(bstnode *root, int data)
{ if (root == NULL)
{
    return true;
}

    if (root->data <= data && isbstlesser(root->left, data) && isbstlesser(root->right, data))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isbstgreater(bstnode *root, int data)
{if (root == NULL)
{
    return true;
}

    if (root->data >= data && isbstgreater(root->left, data) && isbstgreater(root->right, data))
    {
        return true;
    }
    else
    {
        return false;
    }
}                                                                                         ///这里递归遍历太多，可能会栈溢出，所以须改进//

bool isbst(bstnode *root)//判断是否为二叉树
{if (root == NULL)
{
    return true;

}
if (isbstlesser(root->left, root->data) && isbstgreater(root->right, root->data) && isbst(root->left) && isbst(root->right))
{
    return true;
}
else {
    return false;
}
}*/
bool isbst(bstnode *root, int min, int max)//判断是否为二叉树，但和1上面不同，这个是用最大最小值判断
{
    // 如果根节点为空，则返回true
    if (root == NULL)
    {
        return true;
    }
    // 如果根节点的值在最小值和最大值之间，并且左子树和右子树也满足二叉树的条件，则返回true
    if (root->data >=min&&root->data <=max&&isbst(root->left, min, root->data) && isbst(root->right, root->data, max))
    {
        return true;
    }
    // 否则返回false
    else {return false;}
}
struct bstnode *del (struct bstnode *root, int data) ////////删除节点
{
    if (root == NULL)//空的没得删
    {
        return root;
    }
    //找节点
    else if (data < root->data)
    {
       root->left = del (root->left, data);//如果小于，递归从左查找
      // del (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = del (root->right, data);//如果大于，递归从右查找
       // del (root->right, data);
    }
    else//找到要删除的节点了
    { if (root->left == NULL&&root->right == NULL)
    {
         delete(root);             ///////////无左右孩子的情况，直接free，不用额外处理
        root = NULL;
        

    }
        else if (root->left == NULL)
        {
            struct bstnode *temp = root;
            root = root->right;         
            delete(temp);
       
        
        }
        else if (root->right == NULL)                         //有一个孩子的情况，需要接回原来的树上
        {
            struct bstnode *temp = root;
            root= root->left;
            delete(temp);
         
            
        }
        else
        {
            struct bstnode *temp = findmin(root->right);
            root->data = temp->data;                                        //有两个孩子的情况，需要找到后继节点，将后继节点的值赋给当前节点，然后删除后继节点，也是最麻烦的了
            root->right = del (root->right, temp->data);
        }
    }
    return root;
}
struct bstnode*getsuccessor(struct bstnode*root,int data)//为了后面中序遍历输出设计的
{
    // 查找节点
    struct bstnode*current=find(root,data);
    // 如果根节点为空，返回NULL
    if(root==NULL){return NULL;}
   // 如果当前节点的右子节点不为空，返回右子节点的最小值
   if(current->right!=NULL)
    {   struct bstnode*temp=current->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp;
    }
    // 否则，查找当前节点的后继节点
    else {
        // 初始化后继节点和父节点
        struct bstnode*successor=NULL;
        struct bstnode*parent=root;
        // 遍历树，查找后继节点
        while(parent!=current)
        {
            // 如果当前节点的值小于父节点的值，后继节点为父节点，父节点为父节点的左子节点
            if(current->data<parent->data)
            {
               successor=parent;
               parent=parent->left;
            }
            // 否则，父节点为父节点的右子节点
            else
            {
                parent=parent->right;
            }
        }
       // 返回后继节点
       return successor;
    }
    }
    struct bstnode* zhongxvshuchu(struct bstnode*root)//中序遍历输出，递归
    { if (root == NULL)
    {
        return NULL;
    }
    else{
        struct bstnode*current=findmin(root);//找到最小节点
            cout<<current->data<<" ";//输出最小节点的值
        while (current!=NULL)
        {
          current=getsuccessor(root,current->data);//找到后继节点
          cout<<current->data<<" ";//输出后继节点的值
        }
    }
    return 0;
    }
void preorder(struct bstnode *root)//前序输出
{
    if (root == NULL)
    {
        return;//判断空结束
    }
    else
    {
    cout << root->data << " ";//输出当前节点
    preorder(root->left);//调用递归
    preorder(root->right);
    }                                                                        //前中后序输出只是输出顺序不同
}
void inorder(struct bstnode *root)//中序输出
{
    if (root == NULL)
    {
        return;//空就返回
    }
    else
    {
    inorder(root->left);//调用递归，输出左子树
    cout << root->data << " ";//输出当前节点
    inorder(root->right);//调用递归，输出右子树
    }
}
void postorder(struct bstnode *root)//后序输出
{
    if (root == NULL)
    {
        return;//空就返回
    }
    else
    {
    postorder(root->left);//调用递归，输出左子树
    postorder(root->right);//调用递归，输出右子树
    cout << root->data << " ";//输出当前节点
    }
}
int main()
{
    bstnode *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    int number;
    //int minimum=2;
    //int maxinum=8;
    cout<<"层序输出"<<"\n";
    levelorder(root);
    cout<<"enter your number to search:"<<endl;
    cin>>number;
    if(search(root,number)==true)
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }
    //findmin(root);                                                        //      5        //
    //findmax(root);                                                        //    /   \      //
    //findheight(root);                                                    //     3     7    //                                                               
                                                                           //    / \   / \   //
   //cout<< findheight(root)<<endl;///////输出2的原因：                    //    2   4  6  8   //
cout<<"enter your number to delete:"<<endl;
cin>>number;
del(root, number);
levelorder(root);
cout<<"enter your number to insert:"<<endl;
cin>>number;
root=insert(root,number);
levelorder(root);
cout<<"前序输出:"<<endl;
preorder(root);
cout<<"\n";
cout<<"中序输出"<<endl;
inorder(root);
cout<<"\n";
cout<<"后序输出"<<endl;
postorder(root);
return 0;
}

