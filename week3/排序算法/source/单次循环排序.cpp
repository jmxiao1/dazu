#include <iostream>
using namespace std;

int main()
{
    int a[] = { 0, 2, 1, 2, 0, 1, 0, 2, 1, 0, 1, 2 };
    printf("排序前:");
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n");
    int p0 = 0 ;  // 定义指针p0，指向数组a的第一个元素
    int p2 = (sizeof(a)/sizeof(a[0])) - 1  ; // 定义指针p2，指向数组a的最后一个元素
       int  i = 0 ; // 定义指针i，用于遍历数组a
    
        while (i <= p2) // 当指针i小于等于指针p2时，循环执行
        {
            if (a[i] == 0) // 如果数组a的第i个元素为0
            {int temp= a[i]; // 定义临时变量temp，保存数组a的第i个元素
                a[i]=a[p0]; // 将数组a的第i个元素与数组a的第p0个元素交换
                 a[p0] =  temp; // 将数组a的第p0个元素与数组a的第i个元素交换
                p0 += 1; // 指针p0向后移动一位
                i += 1; // 指针i向后移动一位
            }  
            else if(a[i] == 2) // 如果数组a的第i个元素为2
              {
                int temp= a[i]; // 定义临时变量temp，保存数组a的第i个元素
                a[i]=a[p2]; //交换
                a[p2] = temp;
               p2 -= 1 ; //更新p2
            }
            else if (a[i] == 1)
            {
               
                i += 1;
            }
        }
    printf("排序后:");
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

