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
    //return 2 * hanoiSteps(n - 1) + 1;，遞迴
}

int main() 
{
    int n;
    cin >> n; // 讀取輸入的盤子數量

    // 計算並輸出所需的步驟數
    cout << hanoiSteps(n) << endl;

    return 0;
}



#include <iostream>
using namespace std;

// 河內塔遞迴函式
void hanoi(int n, char from_rod, char to_rod, char aux_rod) 
{
    if (n == 1) 
    {
        // 當只剩下一個圓盤時，直接將其從 from_rod 移動到 to_rod
        cout << "將盤子 " << n << " 從 " << from_rod << " 移動到 " << to_rod << endl;
        return;
    }

    // 將 n-1 個圓盤從 from_rod 移動到 aux_rod，使用 to_rod 作為輔助
    hanoi(n - 1, from_rod, aux_rod, to_rod);

    // 將第 n 個（最大的）圓盤從 from_rod 移動到 to_rod
    cout << "將盤子 " << n << " 從 " << from_rod << " 移動到 " << to_rod << endl;

    // 將 n-1 個圓盤從 aux_rod 移動到 to_rod，使用 from_rod 作為輔助
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// 主函式
int main() 
{
    int n; // 圓盤的數量
    cout << "輸入圓盤的數量: ";
    cin >> n;
    
    // 執行河內塔問題，將 n 個圓盤從 A 移動到 C，B 是輔助柱
    hanoi(n, 'A', 'C', 'B');

    return 0;
}
