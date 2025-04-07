#include <iostream>
using namespace std;
// 定义一个函数，用于将数组a中从left到right的元素进行划分，返回划分后的基准元素的位置
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


int main()
{
    int a[10] = { 5, 2, 9, 4, 7, 6, 1, 8, 3, 0 };
    quicksort(a,1,9);
    for(int i=1;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}