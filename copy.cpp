#include <iostream>

using namespace std;

void copy(int *begin, int *end, int *result) //遍歷從 begin 到 end 的元素，將每個元素複製到 result 陣列中
{
    int index = 0;
    for (int *p = begin; p != end; p++) 
    {
        *(result + index++) = *p;
    }
}

void copy_(int *arr, int size, int *result) //arr 陣列的前 size 個元素，將每個元素複製到 result 陣列
{
    for (int i = 0; i < size; i++) 
    {
        result[i] = arr[i];
    }
}

int main() 
{
    // init
    int *arr, *copied, size;
    cin >> size;
    arr = new int[size];// 動態分配記憶體給 arr 陣列
  
    for (int i = 0; i < size; i++) // 讀取陣列元素
    {
        cin >> arr[i];
    }

    // copy
    copied = new int[size];// 動態分配記憶體給 copied 陣列
    copy_(arr, size, copied);//// 使用 copy_ 函數複製陣列
    // copy(arr, arr+size, copied);

   // 輸出複製後的陣列
    for (int i = 0; i < size; i++) 
    {
       if (i > 0) 
        {
        cout << " "; // 在不是第一個元素之前加一個空格
        }
        cout << copied[i];
    }
    cout << "\n";//最後換行。
    return 0;
}
