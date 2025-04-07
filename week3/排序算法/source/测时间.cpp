#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <chrono>
using namespace std;

void InsertSort(int a[], int n)
{
    // 从第二个元素开始遍历数组
    for (int i = 1; i < n; i++)
    {
        // 将当前元素保存到临时变量temp中
        int temp = a[i];
        // 将当前元素前一个元素的下标保存到变量j中
        int j = i - 1;
        // 当j大于等于0且temp小于a[j]时，将a[j]的值赋给a[j+1]，并将j减1
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        // 将temp的值赋给a[j+1]
        a[j + 1] = temp;
    }
}
//归并排序
void merge(int a[], int p, int q, int r)
{
    // 计算左半部分的长度
    int n1 = q - p +1; 
    // 计算右半部分的长度
    int n2 = r - q;
    // 定义左半部分和右半部分的数组
    int L[n1+1], R[n2+1];
    // 将左半部分的元素复制到L数组中
    for (int i = 0; i < n1; i++)
        L[i] = a[p + i];
    // 将右半部分的元素复制到R数组中
    for (int j = 0; j < n2; j++)
        R[j] = a[q + j+1];
  L[n1] = 99999999; //设置哨兵
  R[n2] = 99999999;
    int i=0;int j=0;
    // 按大小合并两个有序数组
    for (int k = p; k <= r; k++)
    {
        // 如果左半部分的元素小于等于右半部分的元素，将左半部分的元素复制到a数组中
        if (L[i] <= R[j])
        {    a[k] = L[i++];}
        // 否则，将右半部分的元素复制到a数组中
        else
        {  a[k] = R[j++];}
    } 
}
void mergeSort(int a[], int p, int r) //拆分数组进行递归
{
    if (p < r)
    {
       int q= (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

//快速排序
int partition(int a[],int left,int right)
{
    // 将基准元素设为数组a中最后一个元素
    int x=a[right];
    // 定义一个指针i，指向left-1
    int i=left-1;
    // 遍历数组a中从left到right-1的元素
    for(int j=left;j<right;j++)
    {
        // 如果当前元素小于等于基准元素
        if(a[j]<=x)
        {
            // 将指针i向后移动一位
            i++;
            // 交换指针i和j指向的元素
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        }

    }
    // 将基准元素与指针i+1指向的元素交换
    int temp=a[i+1];
        a[i+1]=a[right];
        a[right]=temp;
    // 返回指针i+1的位置
    return i+1;

}
// 定义一个函数，用于对数组a中从left到right的元素进行快速排序
void quicksort(int a[],int left,int right)
{if(left<right)
    {
    // 调用partition函数，得到划分后的基准元素的位置
    int mid;
    mid=partition(a,left,right);
    // 递归地对基准元素左边的元素进行快速排序
    quicksort(a,left,mid-1);
    // 递归地对基准元素右边的元素进行快速排序
    quicksort(a,mid+1,right); 
    } 
}



//计数排序
void CountingSort(int a[], int n) {
    int max = a[0];
    // 找到数组中的最大值
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    int * count = new int[max + 1](); // 初始化为0
    // 计数
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    int index = 0; // 排序
    // 根据计数数组，将元素按顺序放入原数组
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            a[index++] = i;
            count[i]--;
        }
    }
    delete count;
}
int main()
{     srand(time(NULL));
    int n;
    double totaltime;
    int a[200000];
    for(int i=0;i<200000;i++)
    {
        a[i]=rand();
    }
    cout<<"选择层次："<<endl;
    cout<<"1.10000"<<endl;
    cout<<"2.50000"<<endl;
    cout<<"3.200000"<<endl;
    int choice;
    cin>>choice;
    if(choice==1)
    {

        n=10000;
    }
    else if(choice==2)
    { n=50000;
    }
    else if(choice==3)
    {n=200000;
    }
    cout<<"选择排序算法："<<endl;
    cout<<"1.插入排序"<<endl;
    cout<<"2.归并排序"<<endl;
    cout<<"3.快速排序"<<endl;
    cout<<"4.计数排序"<<endl;
    int choice1;
    cin>>choice1;
    if(choice1==1)
    {
        clock_t start,finish;
        start=clock();
        InsertSort(a,n);
        finish=clock();
        totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    }
    else if(choice1==2)
    {
        clock_t start,finish;
        start=clock();
        mergeSort(a,0,n-1);
        finish=clock();
        totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    }
    else if(choice1==3)
    {
        clock_t start,finish;
        start=clock();
        quicksort(a,0,n-1);
        finish=clock();
        totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    }
    else if(choice1==4)
    {
        clock_t start,finish;
        start=clock();
        CountingSort(a,n);
        finish=clock();
        totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    }
    cout<<"The run time is:"<<totaltime<<"s"<<endl;
    return 0;
}