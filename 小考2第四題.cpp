template <class T>
class Queue 
{  // A finite ordered list with zero or more elements.
   public:
    Queue(int queueCapacity = 10);//建構子
    bool IsEmpty() const;//判斷佇列是否為空
      T& Front() const;//獲取佇列前端元素
    T& Rear() const;//獲取佇列後端元素
    void Push(const T& item); //將元素插入佇列尾端   
    void Pop();//從佇列前端刪除元素

   private:
    T* queue;      //用來存放佇列元素的陣列
    int front,     //指向佇列頭的前一個位置
        rear,      //指向佇列尾的元素位置
        capacity;  //陣列的容量
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) 
{
   //如果指定的容量小於1，會丟出一個異常。
    if (capacity < 1) throw "Queue capacity must be > 0.";
    queue = new T[capacity];創建一個 Queue 物件時，可以指定佇列的初始容量（默認為10）。
    front = rear = 0;//front 和 rear 初始化為 0，表示此時佇列為空。
}

template <class T>
inline bool Queue<T>::IsEmpty() const 
{
   //這個函數用來檢查佇列是否為空。如果 front 等於 rear，表示佇列為空
    return front == rear;
}

template <class T>
inline T& Queue<T>::Front() const 
{
   //如果佇列為空，會丟出異常。
    if (IsEmpty()) throw "Queue is empty. No front element.";
   //前端元素時，使用 (front + 1) % capacity 計算前端元素的位置。
    return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const 
{
    if (IsEmpty()) throw "Queue is empty. No front element.";
    return queue[rear];//rear 指向的是尾端元素。
}

template <class T>
void Queue<T>::Push(const T& x) 
{          // Add x at rear of queue
    if ((rear + 1) % capacity == front) 
    {  
       //佇列已滿，需要擴展容量
        T* newQueue = new T[2 * capacity];
        // 原佇列中有效元素的起始位置。根據 start 的值來決定如何複製資料。
        int start = (front + 1) % capacity;
        if (start < 2) 
        {
            // 前端元素與後端元素之間沒有環繞
            copy(queue + start, queue + capacity, newQueue);
           //直接複製前端到尾端之間的元素到 newQueue
            copy(queue, queue + rear + 1, newQueue + capacity - start);
        }
        // 指向新佇列的末尾
        front = 2 * capacity - 1;
        rear = capacity - 2;//重新設定為舊容量的末端位置
        capacity *= 2;//變為原來的兩倍，指向新佇列。
        delete[] queue;釋放舊的 queue 陣列記憶體
        queue = newQueue;//queue 指向新分配的 newQueue。
    }
    rear = (rear + 1) % capacity;//更新 rear 指標，使其指向下一個可插入位置
    queue[rear] = x;//新元素 x 插入到 rear 指向的位置。
}

template <class T>
void Queue<T>::Pop() 
{  // Delete front element from queue
    if (ISEmpty()) throw "Queue is empty. Connot delete.";
    front = (front + 1) % capacity;
   //更新 front，指向新的前端位置，並顯式呼叫 queue[front].~T() 來銷毀前端元素。
    queue[front].~T();  // destructor for T//呼叫 T 型別的解構函數
}
