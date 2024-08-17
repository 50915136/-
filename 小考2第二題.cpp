template <class T>
class Chain 
{
   public:
    Chain() { first = 0; }  // 建構函數，初始化空鏈表
    ~Chain();               // 解構函數，負責釋放內存
    bool IsEmpty() const { return first == 0; }//判斷鏈表是否為空
    
    int IndexOf(const T& theElement) const;//查找元素位置
    void Delete(int theIndex);//刪除指定位置的元素
    void Insert(int theIndex, const T& theElement);//在指定位置插入元素

   private:
    ChainNode<T>* first;//指向鏈表頭的指針
};

template <class T>
int Chain<T>::IndexOf(const T& theElement) const 
{
    
    ChainNode<T>* currentNode = first;//指向鏈表節點的指針 
    int index = 0;  // 記錄當前節點在鏈表中的索引位置
   //檢查每個節點的 data 是否等於 theElement
   /*currentNode != NULL確保遍歷不會超出鏈表的末尾。
currentNode->data != theElement：檢查當前節點的 data 是否等於要查找的
*/
    while (currentNode != NULL && currentNode->data != theElement) 
    {
        // move to next node
        currentNode = currentNode->link;//移動到下一個節點 
        index++;//索引位置向後移動一位。
    }
    // make sure we found matching element
    if (currentNode == NULL)
        return -1;
    else
        return index;//找到匹配的元素，返回它的位置
}

template <class T>
void Chain<T>::Delete(int theIndex) 
{
   //如果 first 為 0（即鏈表中沒有任何節點），則拋出一個異常
    if (first == 0) throw "Cannot delete from empty chain";
    ChainNode<T>* deleteNode;
    if (theIndex == 0) //表示要刪除鏈表中的第一個節點。
    {  
        deleteNode = first;//節點指針賦值給 deleteNode
        first = first->link;//first 指針移動到鏈表的下一個節點
    }
    else 
    {  // 指向第一個節點的指針 p，用於遍歷鏈表
        ChainNode<T>* p = first;
        for (int i = 0; i < theIndex - 1; i++) 
        {
           //如果在遍歷過程中p變為0，表示鏈表中沒有這麼多節點，則拋出異常。
            if (p == 0) throw "Delete element does not exist";
            p = p->link;
        }
        deleteNode = p->link;//將 p->link 指針賦值給 deleteNode
        p->link = p->link->link;//指向要刪除節點的下一個節點
    }
    delete deleteNode;//釋放 deleteNode 所指向的記憶體
}

template <class T>
void Chain<T>::Insert(int theIndex, const T& theElement) 
{
   //如果索引小於 0，則拋出一個異常，表示這是一個無效的插入位置。
    if (theIndex < 0) throw "Bad insert index";
    if (theIndex == 0) //新元素插入到鏈表的開頭。
    {
        // 新的節點，其中包含了 theElement 的值，並且將此節點的 link 指向當前的 first
        first = new ChainNode<T>(theElement, first);
    } 
    else 
    {  
        ChainNode<T>* p = first;
       //找到 theIndex 處的前一個節點。
        for (int i = 0; i < theIndex; i++) 
        {
            if (p == 0) throw "Bad insert index";
            p = p->link;
        }
        // 該節點包含 theElement，並且將此新節點的 link 指向原來 p->link 所指向的節點
        p->link = new ChainNode<T>(theElement, p->link);
    }
}
