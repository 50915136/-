// GCD 遞迴
#include <iostream>

using namespace std;

int GCD(int a, int b) 
{
    if (b == 0) return a;  // 終止條件
    return GCD(b, a % b);  // 遞迴
}

int main() 
{
    int n, m;
    while (cin >> n >> m) 
    {
        cout << GCD(n, m) << "\n";
    }
    return 0;
}


// GCD 非遞迴
#include <iostream>

using namespace std;

int GCD(int a, int b) 
{
    while (b != 0) //當 b 不為 0 時，繼續執行
    {
        int temp = a % b;//計算餘數
        a = b;//更新 a 為 b
        b = temp;//更新 b 為餘數
    }
    return a;//當 b 為 0 時，a 為最大公因數
}

int main() 
{
    int n, m;
    while (cin >> n >> m) 
    {
        cout << GCD(n, m) << "\n";
    }
    return 0;
}
