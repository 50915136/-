#include <iostream>
#include <string>

using namespace std;

// &str：一個參考，指向要反轉的字串。
//left：目前要交換的左側字符的位置。
//right：目前要交換的右側字符的位置。
void reverseHelper(string &str, int left, int right) 
{
    if (left >= right) //字串的反轉已經完成，整個字串已經處理完畢。
    {
        return; // 遞迴終止條件
    }
    
    // 交換字元
    swap(str[left], str[right]);//交換字串 str 中位置 left 和 right 的字符。
    
    // 遞迴地處理下一對字符
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
