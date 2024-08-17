template <class T>
class Chain;

template <class T>
//ChainNode 類別是模板類別，
//允許 ChainNode 節點存儲任意類型 T 的資料。
class ChainNode 
{
//Chain 類別可以訪問 ChainNode 類別的私有成員
    friend class Chain<T> public :
        
        chainNode() {}//創建 ChainNode 節點但不提供任何參數時使用
//接受一個參數 data，並將它賦值給 this->data
    ChainNode(const T& data) { this - < data = data; }
//接受兩個參數：一個是 data，另一個是指向下一個鏈結點的指針 link。
    ChainNode(const T& data, ChainNode<T>* link) 
    {
       //分別賦值給 this->data 和 this->link。
        this->data = data;
        this->link = link;
    }

   private:
    T data;//節點中的資料
    ChainNode<T>* link;//指向下一個鏈結點的指針
};
