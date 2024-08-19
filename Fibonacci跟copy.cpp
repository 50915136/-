// Fibonacci
#include <iostream>

using namespace std;

//從 begin 到 end 的數據複製到 result 中。 index 用來跟蹤 result 陣列的當前位置。
void copy(int *begin, int *end, int *result) 
{
    int index = 0;

    for (int *p = begin; p != end; p++) 
    {
        *(result + index++) = *p;
        //將 *p 的值複製到 result 陣列的當前位置，然後將 index 增加 1，移動到下一個位置。
    }

    *(result + index++) = 0;
    //result 陣列的最後一個位置設置為 0。擴展 result 陣列的大小，預留空間。
}

int *DP;//動態分配的整數陣列，用於存儲已計算的 Fibonacci 數值
int sizeOfDP = 1;//DP 陣列的當前大小

int F(int i) 
{
    //檢查 i 是否已經計算過並存儲在 DP 陣列中，如果已經計算過則直接返回 DP[i] 的值。
    if (sizeOfDP > i && DP[i] > 0)
    {
        return DP[i];
    }

    int oldSize = sizeOfDP;

    if (sizeOfDP <= i) //如果 sizeOfDP <= i，則需要擴展 DP 陣列的大小。
    {
        int *tmp = DP;//DP 陣列指針保存在 tmp 變數
        DP = new int[i + 1];//新的 DP 陣列將能夠容納 i + 1 個元素
        copy(tmp, tmp + sizeOfDP, DP);//舊的 DP 陣列中的數據複製到新的 DP 陣列
        sizeOfDP = i + 1;//更新 sizeOfDP 變數，以反映新的 DP 陣列的大小
    }
    // DP[i] = F(i-1)+F(i-2);
    for (int j = oldSize; j < sizeOfDP; j++) 
        {
            DP[j] = DP[j - 1] + DP[j - 2];//從 oldSize 到 sizeOfDP 的 Fibonacci 數字，並更新 DP 陣列。
        }
        
    return DP[i];
}

int Fibonacci(int n) 
{
    if (n < 0) 
    {
        throw "n must be grater then or equal 0";
    } 
    else if (n <= 1) 
    {
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() 
{
    int n;
    DP = new int[2];//初始化 DP 陣列為長度 2
    sizeOfDP = 2;
    DP[0] = 1;//並將 DP[0] 和 DP[1] 設置為 1。
    DP[1] = 1;

    while (cin >> n) 
    {
        cout << F(n) << "\n";//使用 F 函數計算第 n 個 Fibonacci 數字並輸出。
        // cout<<Fibonacci(n)<<"\n";
    }
    return 0;
}
