#include <iostream>
using namespace std;
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
// 快速选择算法，用于在数组中找到第k小的元素
int quickselect(int a[], int left, int right, int k) {
    // 如果数组只有一个元素，直接返回该元素
    if (left == right) {
        return a[left];
    }
    // 将数组分为两部分，并返回枢轴元素的索引
    int pivotIndex = partition(a, left, right);
    // 如果k等于枢轴元素的索引，返回枢轴元素
    if (k == pivotIndex) {
        return a[k];
    // 如果k小于枢轴元素的索引，递归调用quickselect在左半部分查找第k小的元素
    } else if (k < pivotIndex) {
        return quickselect(a, left, pivotIndex - 1, k);
    // 如果k大于枢轴元素的索引，递归调用quickselect在右半部分查找第k小的元素
    } else {
        return quickselect(a, pivotIndex + 1, right, k);
    }
}
int main()
{
    int n;
    cout<<"请输入数组长度"<<endl;
    cin>>n;
    int a[n];
    cout<<"请输入数组元素"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"请输入k"<<endl;
    int k;
    cin>>k;
    cout<<quickselect(a,0,n-1,k-1)<<endl;
    return 0;
}