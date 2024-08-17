#include <iostream>
#include <queue>
#include <vector>
#include <functional> 

using namespace std;

// 定義了一個最小堆。優先佇列是一種自動保持順序的資料結構，
//這裡使用了 greater<int> 來使其成為最小堆（最小的元素總是位於堆頂）。
long long computeMinCost(vector<int>& numbers) 
{    
    // 將向量中的所有數字插入到最小堆
    for (int num : numbers) 
    {
        minHeap.push(num);
    }
    
    long long totalCost = 0;
    
    // 元素數量大於1時，迴圈繼續執行。將兩個最小的數字相加直到堆中只剩下一個數字。
    while (minHeap.size() > 1) 
    {
        // 提取並移除堆中的最小元素
        int first = minHeap.top();
        minHeap.pop();
        
        //提取並移除第二小的元素
        int second = minHeap.top();
        minHeap.pop();
        
        // 兩個最小元素相加，相加的成本累加到總成本
        long long cost = first + second;
        totalCost += cost;
        
        // 相加的結果重新插入堆
        minHeap.push(cost);
    }
    
    return totalCost;
}

int main() 
{
    int n;
    while (cin >> n && n != 0) 
    {
        //一個大小為 n 的向量來存儲輸入的數字。
        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> numbers[i];
        }
        
        // 計算並輸出最小成本。
        cout << computeMinCost(numbers) << endl;
    }
    return 0;
}
