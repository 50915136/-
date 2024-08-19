#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Term 
{
public:
    int coef; // 係數
    int exp;  // 指數

    Term(int c = 0, int e = 0) : coef(c), exp(e) {}//初始化係數和指數。

    // 用於排序，宣告 Term 類別內重載 < 運算符。接受另一個 Term 類的物件作為參數，並返回 bool 類型的結果。
    bool operator<(const Term& other) const //const 表示這個函數不會修改類別的任何成員變數。
    {
        return exp > other.exp; // 重載小於運算符，用於根據指數對 Term 進行排序，指數從大到小。
    }

    // 輸出項
    void print(bool first) const //格式化和輸出多項式的單項式
  {
        if (coef != 0) 
        {
            if (!first && coef > 0) 
            {
                cout << "+";//不是第一項且係數為正，則在輸出前加上 +
            }
            if (coef != 1 && coef != -1) 
            {
                cout << coef;//係數不是 1 或 -1，直接輸出係數的數值
            } 
            else if (coef == -1) 
            {
                cout << "-";//係數為 -1，僅輸出 - 符號
            }
            if (exp > 0) //指數大於零，輸出 x。如果指數為零，則不顯示 x。
            {
                cout << "x";
                if (exp > 1) 
                {
                    cout << "^" << exp;//指數大於 1，輸出 ^
                }
            }
        }
    }
};

class Polynomial {
private:
    vector<Term> terms; // vector動態調整大小容器，儲存 Term 物件，即多項式的所有項

    void addTerm(int coef, int exp) //將多項式的項添加到 terms 向量中。
  {
        if (coef == 0) return; // 係數為 0，則不添加該項

        //find_if 函數查找 terms 向量中是否已經存在具有相同指數 exp 的項。
        //find_if在指定範圍內查找符合條件的元素
        auto it = find_if(terms.begin(), terms.end(), [exp](const Term& t) { return t.exp == exp; });
        if (it != terms.end()) 
        {
            it->coef += coef;//找到的項的係數與新係數 coef 相加。
            if (it->coef == 0) 
            {
                terms.erase(it); // 移除係數為 0 的項。
            }
        } 
        else 
        {
            terms.push_back(Term(coef, exp));//新的 Term 物件（包含係數和指數）添加到 terms 向量中。
        }
    }

public:
    Polynomial() {}

    // 初始化 Polynomial 類別
    Polynomial(const vector<int>& coefficients, const vector<int>& exponents) //初始化多項式，根據係數和指數創建項目，並對項目進行排序。
    {
        for (size_t i = 0; i < coefficients.size(); ++i) //遍歷係數和指數的向量
        {
            addTerm(coefficients[i], exponents[i]);//係數和指數添加到多項式中
        }
        sort(terms.begin(), terms.end());// terms 向量中的 Term 物件按指數從大到小排序。
    }

    Polynomial add(const Polynomial& other) const //當前多項式與另一個多項式相加，並返回結果多項式。
    {
        Polynomial result = *this;//新的 Polynomial 物件 result，並初始化為當前多項式（*this）。
        for (const Term& t : other.terms) //遍歷 other 多項式中的所有項
        {
            result.addTerm(t.coef, t.exp);//other 多項式中的每個項添加到 result 中。
        }
        return result;
    }

    void print() const //打印多項式，格式化顯示每一項，處理項目之間的符號和格式。
    {
        if (terms.empty())//terms 向量為空，表示多項式為 0，直接輸出 0。 
        {
            cout << "0";
        } 
        else 
        {
            bool first = true;//初始化 first 為 true，用於標記當前項是否為第一項。
            for (const Term& t : terms) 
            {//調用 Term 類的 print 函數輸出當前項。傳入 first 參數以決定是否需要在輸出前添加 + 符號。
                t.print(first);
                first = false;//將 first 設為 false，表示後續項不再是第一項。
            }
        }
        cout << endl;
    }
};

int main() 
{
    int m, n;
    while (cin >> m >> n) 
    {
        vector<int> coeffA(m), expA(m);//存儲多項式 A 的係數和指數
        vector<int> coeffB(n), expB(n);//存儲多項式 B 的係數和指數

        for (int i = 0; i < m; ++i) 
        {
            cin >> coeffA[i] >> expA[i];//讀取 m 個係數和指數，存儲在 coeffA 和 expA
        }
        for (int i = 0; i < n; ++i) 
        {
            cin >> coeffB[i] >> expB[i];//讀取 n 個係數和指數，存儲在 coeffB 和 expB
        }
      
//創建 Polynomial 類的兩個物件 polyA 和 polyB。這些物件分別代表多項式 A 和多項式 B。
        Polynomial polyA(coeffA, expA);
        Polynomial polyB(coeffB, expB);
  //result 物件代表了多項式 A 和多項式 B 的和。
        Polynomial result = polyA.add(polyB);
        result.print();
    }
    return 0;
}
