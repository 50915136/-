#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用二分搜尋算法來尋找目標值
int binarySearch(const vector<int>& arr, int target) 
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) 
        {
            return mid; // 找到目標值，返回其索引
        }
        else if (arr[mid] < target) 
        {
            left = mid + 1; 
            // 目標值必定在右半部分，將 left 指標移至 mid + 1。
        }
        else 
        {
            right = mid - 1; // 搜尋左半部分
            //目標值必定在左半部分，將 right 指標移至 mid - 1。
        }
    }

    return -1; // 未找到目標值，返回 -1
}

int main() 
{
    int numTestCases;//接下來要進行的測試次數。
    cin >> numTestCases;

    while (numTestCases--) 
    {
        int length;//陣列的長度
        cin >> length;

        vector<int> arr(length);//長度為 length 的向量 arr
        for (int i = 0; i < length; ++i) 
        {
            cin >> arr[i];
        }

        // 使用 std::sort 來對陣列進行排序
        sort(arr.begin(), arr.end());

        int target;
        cin >> target;

        int result = binarySearch(arr, target);
        
        if (result != -1) 
        {
            cout << result  << endl;
        } 
        else 
        {
            cout << "Not Found" << endl;
        }
    }

    return 0;
}
