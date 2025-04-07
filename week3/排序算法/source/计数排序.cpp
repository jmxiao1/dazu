#include <iostream>
using namespace std;

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


int main() {
    int a[] = { 2, 5, 3, 0, 2, 3, 0, 3 };
    int n = sizeof(a)/sizeof(a[0]) ;
    CountingSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}