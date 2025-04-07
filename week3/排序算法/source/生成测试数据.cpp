#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    srand(time(NULL));
    int n = 10;
    ofstream fout("test.txt");
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    random_shuffle(a.begin(), a.end());
    for (int i = 0; i < 10; i++)
        fout << a[i % n] << "\n"  ;
    fout.close();
    return 0;

}