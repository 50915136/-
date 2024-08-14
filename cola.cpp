#include <iostream>

using namespace std;

int main() 
{
    int n;
    while (cin >> n) 
    {
        int total = n;  // 初始可樂數量
        int bottles = n;  // 初始空瓶數

        while (bottles >= 3) 
        {
            int new_cola = bottles / 3;
            total += new_cola;
            bottles = bottles % 3 + new_cola;
        }

        // 如果最後剩下2個空瓶，可以借一個空瓶來換一瓶可樂
        if (bottles == 2) 
        {
            total += 1;
        }

        cout << total << endl;
    }
    return 0;
}
