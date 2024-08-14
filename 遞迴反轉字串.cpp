#include <iostream>
#include <string>

using namespace std;

// 遞迴反轉字串的輔助函數
void reverseHelper(string &str, int left, int right) 
{
    if (left >= right) 
    {
        return; // 遞迴終止條件
    }
    
    // 交換字元
    swap(str[left], str[right]);//將目前字串的左端和右端字元交換
    
    // 遞迴處理下一對字元
    reverseHelper(str, left + 1, right - 1);
}

// 主函數
int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        reverseHelper(line, 0, line.length() - 1);//left 設為字串開頭，right 設為字串結尾。
        cout << line << endl;
    }
    return 0;
}
