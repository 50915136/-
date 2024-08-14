#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n; // 行數
    cin >> n; // 讀取行數

    while (n--) 
    {
        int S; // 每行的數字個數
        cin >> S; // 讀取數字個數
        
        vector<int> numbers(S); // 用於存儲每行的數字

        // 讀取數字
        for (int i = 0; i < S; ++i) 
        {
            cin >> numbers[i];
        }

        // 輸出反轉後的數字
        for (int i = S - 1; i >= 0; --i) // 從最後一個數字開始到第一個數字
        { 
            cout << numbers[i];
            if (i > 0) cout << " "; // 除了最後一個數字之外，其他數字之間加空格
        }
        cout << endl; // 換行
    }

    return 0;
}
