#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void radixCountingSort(vector<int>& arr) {
    // 找到数组中的最大值
    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;
    // 从个位开始，逐位进行排序
    while (maxVal / exp > 0) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);
        // 统计每个数字出现的次数
        for (int i = 0; i < arr.size(); i++) {
            
            // 将数字除以exp并取余数，得到该位上的数字
            count[(arr[i] / exp) % 10]++;
        }
        // 计算每个数字在输出数组中的位置
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        // 将数字按照统计的顺序放入输出数组中
        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        // 将输出数组中的数字复制回原数组
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];

        }
        // 位数加1
        exp *= 10;

        }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixCountingSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}