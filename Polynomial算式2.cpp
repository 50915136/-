#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Polynomial;
class Term 
{
    friend Polynomial;

   private:
    float coef;
    int exp;
};

class Polynomial 
{
   private:
    int capacity;

   public:
    int terms;
    Term *termsArray;
    Polynomial();
    Polynomial Add(Polynomial b);
    Polynomial Mult(Polynomial b);
    float Eval(float f);
    void newTerm(float coef, int exp);
    void output();
};

int main() 
{
    int n, m;
    while (cin >> n >> m) 
    {
        Polynomial p1, p2;
        int c, t;
        while (n--) 
        {
            cin >> c >> t;
            p1.newTerm(c, t);
        }
        while (m--) 
        {
            cin >> c >> t;
            p2.newTerm(c, t);
        }
        Polynomial result = p1.Add(p2);
        result.output();
    }
    return 0;
}

Polynomial::Polynomial() : capacity(2), terms(0) { termsArray = new Term[capacity]; }
void Polynomial::newTerm(float coef, int exp) 
{
    if (capacity == terms) 
    {
        capacity *= 2;
        Term *temp = new Term[capacity];
        copy(termsArray, termsArray + terms, temp);
        delete[] termsArray;
        termsArray = temp;
    }
    //指向 Term 類型物件的指標，也就是一個動態分配的陣列，
    //訪問 termsArray 陣列中的第 terms 個 Term 物件。
    //可以直接讀取或修改該項目的係數值。
    termsArray[terms].coef = coef;
    termsArray[terms++].exp = exp;
}

Polynomial Polynomial::Add(Polynomial b) 
{
    int apos = 0, bpos = 0;//跟蹤當前處理的 termsArray和 b.termsArray的索引。
    Polynomial c;
    while (apos < terms && bpos < b.terms) //循環持續執行，直到兩個多項式其中之一的所有項目都被處理完畢。
    {
        if (termsArray[apos].exp == b.termsArray[bpos].exp) 
        {
            //係數相加，並將結果儲存在 tmp 中。自增索引以處理下一個項目
            float tmp = termsArray[apos++].coef + b.termsArray[bpos++].coef;
            if (tmp) c.newTerm(tmp, termsArray[apos - 1].exp);//將其作為係數與相應的指數添加到結果多項式 c 中。
        } 
        else if (termsArray[apos].exp > b.termsArray[bpos].exp) 
        {
            c.newTerm(termsArray[apos].coef, termsArray[apos].exp);
            apos++;
        } 
        else 
        {
            c.newTerm(b.termsArray[bpos].coef, b.termsArray[bpos].exp);
            bpos++;
        }
    }//當前多項式還有剩餘的項目，則將其全部添加到結果多項式 c 中。
    for (int i = apos; i < terms; i++) c.newTerm(termsArray[i].coef, termsArray[i].exp);
    for (int i = bpos; i < b.terms; i++) c.newTerm(b.termsArray[i].coef, b.termsArray[i].exp);
    return c;
}

Polynomial Polynomial::Mult(Polynomial b) 
{
    Polynomial c;
    for (int apos = 0; apos < terms; apos++) // 遍歷第一個多項式的每一項
    {
        for (int bpos = 0; bpos < b.terms; bpos++) // 遍歷第二個多項式的每一項
        {
            int Exp = termsArray[apos].exp + b.termsArray[bpos].exp, cpos = 0;//兩項相乘後的指數
            bool flag = true;
            while (flag && cpos < c.terms) //查找結果多項式 c 中是否已存在相同指數的項
            {
                if (c.termsArray[cpos].exp == Exp) 
                {
                    flag = false;//// 設置 flag 為 false，表示找到了
                    c.termsArray[cpos].coef += termsArray[apos].coef * b.termsArray[bpos].coef;//係數相加
                }
                cpos++;//檢查下一項
            }// 新增項，指數為 Exp，係數為兩項的係數乘積
            if (flag) c.newTerm(termsArray[apos].coef * b.termsArray[bpos].coef, Exp);
        }
    }
    return c;
}

float Polynomial::Eval(float f) 
{
    float ans;
    for (int i = 0; i < terms; i++) 
    {
        ans += termsArray[i].coef * pow(f, termsArray[i].exp);
    }
    return ans;
}

void Polynomial::output() 
{
    bool flag = true;
    for (int i = 0; i < terms; i++) 
    {
        flag = false;
        if (termsArray[i].exp == 0) 
        {
            cout << termsArray[i].coef;
        } 
        else if (i == terms - 1) 
        {
            if (termsArray[i].exp == 1)
                cout << termsArray[i].coef << "x";
            else
                cout << termsArray[i].coef << "x^" << termsArray[i].exp;
        } 
        else 
        {
            if (termsArray[i].exp == 1)
                cout << termsArray[i].coef << "x+";
            else
                cout << termsArray[i].coef << "x^" << termsArray[i].exp << "+";
        }
    }
    if (flag) cout << "0";
    cout << "\n";
}
