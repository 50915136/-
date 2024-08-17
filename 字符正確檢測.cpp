#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
堆疊的初始化：創建一個空的堆疊 s 用來存儲括號。
遍歷字串：逐字元檢查字串中的每個字符 ch。
遇到開括號：如果遇到 (、[ 或 {，則將其推入堆疊。
遇到閉括號：
檢查堆疊是否為空。如果為空，表示沒有對應的開括號，返回 false。
如果不匹配，返回 false。
如果匹配，將堆疊頂部元素彈出。
*/
// 函數來檢查括號字符串是否正確
bool isValid(const string& str) 
{
    stack<char> s;
    for (char ch : str) 
    {
        switch (ch) 
        {
            case '(': case '[': case '{':
                s.push(ch); // 如果是開括號，將其推入堆疊
                break;
            case ')':
                if (s.empty() || s.top() != '(') return false;
                s.pop(); //如果是閉括號且匹配堆疊頂部的開括號，將堆疊頂部元素彈出
                break;
            case ']':
                if (s.empty() || s.top() != '[') return false;
                s.pop(); //如果是閉括號且匹配堆疊頂部的開括號，將堆疊頂部元素彈出
                break;
            case '}':
                if (s.empty() || s.top() != '{') return false;
                s.pop(); //如果是閉括號且匹配堆疊頂部的開括號，將堆疊頂部元素彈出
                break;
            default:
                return false; // 如果遇到其他字符，返回錯誤
        }
    }
    return s.empty(); // 最終栈應該是空的
}

int main() 
{
    int n;
    cin >> n; // 讀取字符串數量
    cin.ignore(); // 忽略換行符

    for (int i = 0; i < n; ++i) 
    {
        string str;
        getline(cin, str); // 讀取每一行字符串
        if (isValid(str)) 
        {
            cout << "Yes" << endl;
        } 
        else 
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
