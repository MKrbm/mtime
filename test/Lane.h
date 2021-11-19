// Lane.h
// 実行レーンクラス
template <typename t_Lane>
class CLane
{
private:
    // enum はクラスの中でも定義できます
    // int 型の定数を使いたい場合によくやります
    enum Const{ LaneSize = 16, };      // レーンのサイズ
    typedef void (t_Lane::*FPLANE)();  // 処理関数の型

private:
    t_Lane* m_pHandlee;         // 操作対象
    FPLANE m_fpLane[LaneSize];  // 実行レーン
    int    m_nLane;             // 処理数

public:
    CLane(t_Lane& rHandlee)
        : m_pHandlee(&rHandlee), m_nLane(0) { }
    void Set(t_Lane& rHandlee)  // オブジェクトのすり替え
        { m_pHandlee = &rHandlee; }

public:
    bool Push(FPLANE fpLane);     // レーンに処理を追加
    void Do();                    // 処理を全実行
    void Clear(){ m_nLane = 0; }  // レーンを全削除
};

// レーンに処理を追加
template <typename t_Lane>
bool CLane<t_Lane>::Push(FPLANE fpLane)
{
    if(m_nLane >= LaneSize)
        return false;
    // この書き方は第７章を参照
    m_fpLane[m_nLane++] = fpLane;
    return true;
}

// 処理を全実行
template <typename t_Lane>
void CLane<t_Lane>::Do()
{
    for(int i = 0; i < m_nLane; i++)
        (m_pHandlee->*m_fpLane[i])();
}