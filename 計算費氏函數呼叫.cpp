#include <iostream>
using namespace std;

// 遞迴計算 F(n) 的函數，並計算遞迴調用的次數
int recursiveCalls = 0;

int recursiveF(int n) 
{
    recursiveCalls++; // 每次呼叫遞迴函數時增加計數
    if (n == 0 || n == 1) 
    {
        return 1;
    }
    return recursiveF(n - 1) + recursiveF(n - 2);
}

// 迭代計算 F(n) 的函數
int iterativeF(int n) 
{
    if (n == 0 || n == 1) 
    {
        return 1;
    }
    int a = 1, b = 1, c;
    for (int i = 2; i <= n; ++i) 
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() 
{
    int n;
    cin >> n; // 讀取輸入的數字 n

    // 計算遞迴調用的次數
    recursiveCalls = 0; // 重置遞迴調用計數器
    int result = recursiveF(n);
    
    // 輸出遞迴調用的次數
    cout << recursiveCalls << endl;

    // 若需要測試迭代函數，可啟用以下代碼：
    // int iterResult = iterativeF(n);
    // cout << "迭代結果: " << iterResult << endl;

    return 0;
}
