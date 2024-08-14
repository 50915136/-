#include <iostream>

using namespace std;

// 計算阿克曼函數 A(m, n)
int ackermann(int m, int n) 
{
    if (m == 0) 
    {
        return n + 1;
    } 
    else if (m > 0 && n == 0) 
    {
        return ackermann(m - 1, 1);
    } 
    else if (m > 0 && n > 0) 
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
    return 0; // 這行理論上永遠不會被執行
}

int main() 
{
    int m, n;
    // 讀取每一行，直到文件結束 (EOF)
    while (cin >> m >> n) 
    {
        cout << ackermann(m, n) << endl;
    }
    return 0;
}
