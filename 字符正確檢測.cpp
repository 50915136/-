#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 函數來檢查括號字符串是否正確
bool isValid(const string& str) 
{
    stack<char> s;
    for (char ch : str) 
    {
        switch (ch) 
        {
            case '(': case '[': case '{':
                s.push(ch); // 推入栈中
                break;
            case ')':
                if (s.empty() || s.top() != '(') return false;
                s.pop(); // 彈出栈頂元素
                break;
            case ']':
                if (s.empty() || s.top() != '[') return false;
                s.pop(); // 彈出栈頂元素
                break;
            case '}':
                if (s.empty() || s.top() != '{') return false;
                s.pop(); // 彈出栈頂元素
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
