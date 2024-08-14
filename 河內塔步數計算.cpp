#include <iostream>
using namespace std;

// 遞迴函數計算河內塔問題所需的步驟數
int hanoiSteps(int n) 
{
    if (n == 0) 
    {
        return 0; // 沒有盤子時，步驟數為 0
    }
    // 計算步驟數，2^n - 1 為移動 n 個盤子的最小步驟數
    return (1 << n) - 1;
}

int main() 
{
    int n;
    cin >> n; // 讀取輸入的盤子數量

    // 計算並輸出所需的步驟數
    cout << hanoiSteps(n) << endl;

    return 0;
}
