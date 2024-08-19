#include <iostream>
#include <stdexcept> // 用於處理異常

using namespace std;

template <class T>
class Queue
{
public:
    Queue(int queueCapacity = 10); // 建構函數
    bool Isempty() const; // 判斷隊列是否為空
    T& Front() const; // 取得隊列前端的元素
    T& Rear() const; // 取得隊列後端的元素
    void Push(const T& item); // 推入元素
    void Pop(); // 彈出隊列前端的元素
    int Size() const; // 取得隊列的大小

private:
    T* queue; // 動態分配的隊列數組
    int front; // 隊列前端的索引
    int rear; // 隊列後端的索引
    int capacity; // 隊列的容量
    int size; // 隊列的當前大小
};

// 建構函數
template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity), front(0), rear(-1), size(0)
{
    if (capacity <= 0) {
        throw invalid_argument("隊列容量必須大於0");
    }
    queue = new T[capacity]; // 動態分配隊列數組
}

// 判斷隊列是否為空
template <class T>
bool Queue<T>::Isempty() const
{
    return size == 0; // 如果 size 為 0，表示隊列為空
}

// 取得隊列前端的元素
template <class T>
T& Queue<T>::Front() const
{
    if (Isempty()) {
        throw runtime_error("隊列為空，無法取得前端元素");
    }
    return queue[front]; // 返回前端元素
}

// 取得隊列後端的元素
template <class T>
T& Queue<T>::Rear() const
{
    if (Isempty()) {
        throw runtime_error("隊列為空，無法取得後端元素");
    }
    return queue[rear]; // 返回後端元素
}

// 推入元素
template <class T>
void Queue<T>::Push(const T& item)
{
    if (size == capacity) { // 如果隊列已滿，擴充容量
        T* newQueue = new T[2 * capacity]; // 新容量為原容量的兩倍
        for (int i = 0; i < size; ++i) {
            newQueue[i] = queue[(front + i) % capacity]; // 複製原有元素
            //(front + i) % capacity：可以確保當 front + i 超過原隊列容量時，索引會回到隊列的起始位置
        }
        delete[] queue; // 釋放原有數組
        queue = newQueue; // 更新隊列指標
        front = 0; // 更新前端索引
        rear = size - 1; // 更新後端索引
        capacity *= 2; // 更新容量
    }
    rear = (rear + 1) % capacity; // 更新後端索引
    queue[rear] = item; // 推入新元素
    ++size; // 更新大小
}

// 彈出隊列前端的元素
template <class T>
void Queue<T>::Pop()
{
    if (Isempty()) {
        throw runtime_error("隊列為空，無法彈出元素");
    }
    front = (front + 1) % capacity; // 更新前端索引
    --size; // 更新大小
}

// 取得隊列的大小
template <class T>
int Queue<T>::Size() const
{
    return size; // 返回隊列的大小
}

// 示範主函數
int main()
{
    try {
        Queue<int> q; // 創建一個整數型別的隊列
        q.Push(1);
        q.Push(2);
        q.Push(3);
        
        cout << "隊列前端元素: " << q.Front() << endl; // 輸出 1
        cout << "隊列後端元素: " << q.Rear() << endl;  // 輸出 3
        
        q.Pop();
        cout << "隊列前端元素: " << q.Front() << endl; // 輸出 2
        
        cout << "隊列大小: " << q.Size() << endl; // 輸出 2
        
        q.Pop();
        q.Pop();
        
        cout << "隊列是否為空: " << (q.Isempty() ? "是" : "否") << endl; // 輸出 是
    }
    catch (const exception &e) {
        cerr << "錯誤: " << e.what() << endl;
    }
    
    return 0;
}
