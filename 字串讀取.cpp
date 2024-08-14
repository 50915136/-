// 字串讀取問題，讀取第六個
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str;
    while (getline(cin, str)) //輸入字串
    {
        if (str[0] == '0') break;
        cout << str[5] << "\n";
    }
    return 0;
}
