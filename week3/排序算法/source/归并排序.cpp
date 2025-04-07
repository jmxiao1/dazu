#include <iostream>
using namespace std;

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
int main()
{
    int a[10] = { 5, 2, 9, 4, 7, 6, 1, 8, 3, 0 };//定义数组
    mergeSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";//输出
    return 0;

}