// swap
//程式碼讀取陣列大小和元素，並在用戶指定的索引上進行交換操作。
//最終輸出經過交換的陣列
#include <iostream>

using namespace std;

void swap(int &x, int &y) //交換兩個整數變數 x 和 y 的值。
{
    int temp = x;
    x = y;
    y = temp;
}

void swap_(int *x, int *y) //交換兩個整數指針所指向的值
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() 
{
    // init
    int n, m;
    cin >> n >> m;//n 表示陣列的大小，m 表示交換的次數。
    int *arr = new int[n];//動態分配一個大小為 n 的整數陣列 arr。
    for (int i = 0; i < n; i++) cin >> arr[i];//讀取 n 個整數並填充到 arr 陣列中。

    // swap process
    for (int i = 0; i < m; i++) //循環 m 次，每次讀取兩個整數 x 和 y，表示需要交換 arr 陣列中索引為 x 和 y 的兩個元素。
    {
        int x, y;
        cin >> x >> y;
        swap(arr[x], arr[y]);//交換這兩個元素的值
    }

    // output
    for (int i = 0; i < n; i++)//輸出交換後的陣列
      {        
        if (i > 0) cout << " "; // 在不是第一個元素之前加一個空格
        cout << arr[i];    
      }
    cout << "\n";
    return 0;
}
