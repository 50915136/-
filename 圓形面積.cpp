#include <iostream>
#include <cmath> // 用於數學函數

using namespace std;

#define M_PI 3.14159265358979323846 // 定義圓周率，這是一個常見的圓周率值

class Circle 
{
private:
    double radius; // 半徑
    double area;   // 面積
    
public:
    // 建構函數
    Circle(double r);
    
    // 解構函數
    ~Circle();
    
    // 取得半徑
    double getRadius() const { return radius; }
    
    // 取得面積
    double getArea() const { return area; }
};

// 建構函數實作
Circle::Circle(double r) : radius(r) 
{
    // 計算圓的面積
    area = M_PI * radius * radius;
}

// 解構函數實作（這裡不需要額外操作）
Circle::~Circle() 
{
}

int main() 
{
    double r;
    // 讀取標準輸入中的半徑，直到輸入結束
    while (cin >> r) 
    {
        // 建立 Circle 物件
        Circle c(r);
        // 輸出圓的面積
        cout << c.getArea() << "\n";
    }
    return 0;
}
