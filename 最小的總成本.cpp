#include <iostream>
#include <queue>
#include <vector>
#include <functional> // 為了使用 std::greater

using namespace std;

// Function to compute the minimum cost to add all numbers
long long computeMinCost(vector<int>& numbers) 
{
    // Min-heap (priority queue) to store the numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Push all numbers into the min-heap
    for (int num : numbers) 
    {
        minHeap.push(num);
    }
    
    long long totalCost = 0;
    
    // While there's more than one element in the heap
    while (minHeap.size() > 1) 
    {
        // Extract the two smallest elements
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        
        // Calculate the cost of adding these two numbers
        long long cost = first + second;
        totalCost += cost;
        
        // Push the result back into the heap
        minHeap.push(cost);
    }
    
    return totalCost;
}

int main() 
{
    int n;
    while (cin >> n && n != 0) 
    {
        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> numbers[i];
        }
        
        // Compute and print the minimum total cost
        cout << computeMinCost(numbers) << endl;
    }
    return 0;
}
