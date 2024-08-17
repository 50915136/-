#include <iostream>
#include <stdexcept> // 用於處理例外

using namespace std;

template <class T>
class Stack
{
public:
    Stack(int stackCapacity = 10); // 建構函數
    bool Isempty() const; // 判斷堆疊是否為空
    T& Top() const; // 取得堆疊頂端的元素
    void Push(const T& item); // 推入元素
    void Pop(); // 彈出堆疊頂端的元素
    int Size() const; // 取得堆疊的大小

private:
    T* stack; // 動態分配的堆疊數組
    int capacity; // 堆疊的容量
    int top; // 堆疊的當前頂端索引
};

// 建構函數
template <class T>
//初始化堆疊的容量為 stackCapacity，並將 top 初始化為 -1，表示堆疊為空。
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity), top(-1)
{
    if (capacity <= 0) 
    {
        throw invalid_argument("堆疊容量必須大於0");
    }
    stack = new T[capacity]; // 動態分配堆疊數組
}

// 判斷堆疊是否為空
template <class T>
bool Stack<T>::Isempty() const
{
    return top == -1; // 如果 top 為 -1，表示堆疊為空
}

// 取得堆疊頂端的元素
template <class T>
T& Stack<T>::Top() const
{
    if (Isempty()) {
        throw runtime_error("堆疊為空，無法取得頂端元素");
    }
    return stack[top]; // 返回頂端元素
}

// 將元素推入堆疊
template <class T>
void Stack<T>::Push(const T& item)
{
    if (top == capacity - 1) 
    { // 如果堆疊已滿，擴充容量
        T* newStack = new T[2 * capacity]; // 新容量為原容量的兩倍
        for (int i = 0; i <= top; ++i) 
        {
            newStack[i] = stack[i]; // 複製原有元素
        }
        delete[] stack; // 釋放原有數組
        stack = newStack; // 更新堆疊指標
        capacity *= 2; // 更新容量
    }
    stack[++top] = item; // 將元素推入堆疊
}

// 彈出堆疊頂端的元素
template <class T>
void Stack<T>::Pop()
{
    if (Isempty()) {
        throw runtime_error("堆疊為空，無法彈出元素");
    }
    --top; // 移除頂端元素
}

// 取得堆疊的大小
template <class T>
int Stack<T>::Size() const
{
    return top + 1; // 堆疊大小為 top + 1
}

// 示範主函數
int main()
{
    //// 創建一個整數型別的堆疊，推入 1、2、3 三個元素。
    try {
        Stack<int> s; 
        s.Push(1);
        s.Push(2);
        s.Push(3);
        
        cout << "堆疊頂端元素: " << s.Top() << endl; // 輸出 3
        
        s.Pop();
        cout << "堆疊頂端元素: " << s.Top() << endl; // 輸出 2
        
        cout << "堆疊大小: " << s.Size() << endl; // 輸出 2
        
        s.Pop();
        s.Pop();
        
        cout << "堆疊是否為空: " << (s.Isempty() ? "是" : "否") << endl; // 輸出 是
    }
    catch (const exception &e) {
        cerr << "錯誤: " << e.what() << endl;
    }
    
    return 0;
}
