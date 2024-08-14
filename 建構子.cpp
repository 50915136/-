#include <iostream>

using namespace std;

class People 
{
public:
    // 建構函數
    People(int init_id);

    // 成員函數
    void change_id(int payload);
    void show_id() const;

private:
    int id;
};

// 建構函數實作
People::People(int init_id) : id(init_id)
{
    // 使用初始化列表設定 id 為 init_id
}

// change_id 函數實作
void People::change_id(int payload) 
{
    id = payload; // 將 id 設定為 payload
}

// show_id 函數實作
void People::show_id() const 
{
    cout << id << endl; // 顯示 id
}

int main() 
{
    People john(200); // 建立一個 id 為 200 的 People 物件
    john.show_id();  // 顯示 id，應該輸出 200

    john.change_id(3000); // 修改 id 為 3000
    john.show_id();  // 顯示 id，應該輸出 3000

    return 0;
}
