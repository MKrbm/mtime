// MemFP1.cpp
#include <iostream>
#include "Lane.h"

using namespace std;
class CCalc
{
private:
    int m_a, m_b;

public:
    CCalc(){ m_a = 0; m_b = 0; }

public:
    // 値のセット
    void Set(int a, int b){ m_a = a; m_b = b; }

public:
    // 各種計算を行い、結果を表示
    void Add();
    void Sub();
    void Mul();
    void Div();
    void Mod();
};

// 足し算
void CCalc::Add()
{
    cout << m_a << " + " <<
            m_b << " = " << m_a + m_b << endl;
}

// 引き算
void CCalc::Sub()
{
    cout << m_a << " - " <<
            m_b << " = " << m_a - m_b << endl;
}

// 掛け算
void CCalc::Mul()
{
    cout << m_a << " * " <<
            m_b << " = " << m_a * m_b << endl;
}

// 割り算
void CCalc::Div()
{
    cout << m_a << " / " <<
            m_b << " = " << m_a / m_b << endl;
}

// 余り
void CCalc::Mod()
{
    cout << m_a << " % " <<
            m_b << " = " << m_a % m_b << endl;
}

int main()
{
    CCalc calc;
    calc.Set(51, 7);

    CLane <CCalc> lane(calc);
    lane.Push(&CCalc::Mul);  // 51 * 7
    lane.Push(&CCalc::Mod);  // 51 % 7
    lane.Push(&CCalc::Add);  // 51 + 7
    lane.Push(&CCalc::Div);  // 51 / 7
    lane.Push(&CCalc::Sub);  // 51 - 7
    lane.Do();

    return 0;
}