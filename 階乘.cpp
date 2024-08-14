#include <iostream>

using namespace std;

// 遞迴函數，計算 N!（Sigma）
int sigma(int n) 
{
    // 基本情況：當 n 為 0 時，返回 0
    if (n == 0) 
    {
        return 0;
    }
    // 遞迴情況：N! = N + (N-1)! 
    return n + sigma(n - 1);
}

int main() 
{
    int n;
    // 持續讀取輸入，直到讀取到 0 為止
    while (cin >> n && n != 0) 
    {
        cout << sigma(n) << endl;
    }
    return 0;
}
