#include <iostream>
using namespace std;

// 插入排序函数
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

int main()
{
    int a[10] = { 9, 6, 7, 5, 8, 2, 3, 0, 1, 4 };
    InsertSort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}