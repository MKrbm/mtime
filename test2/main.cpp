#include <iostream>

class Receiver {
public:
    void Function1() { std::cout << "1" << std::endl; }
    void Function2() { std::cout << "2" << std::endl; }
};

class Sender {
private:
    Receiver *m_pReceiver;
    void (Receiver::*m_pCallbackFunc)();

public:
    Sender(Receiver *pReceiver) : m_pReceiver(pReceiver) {}

    void SetCallbackFunction(void (Receiver::*pFunc)()) {
        m_pCallbackFunc = pFunc;
    }

    void Invoke() {
        (m_pReceiver->*m_pCallbackFunc)();
    }
};

int main() {
    Receiver *pReceiver = new Receiver();
    Sender *pSender = new Sender(pReceiver);

    // コールバック関数を Receiver::Function1() に設定
    pSender->SetCallbackFunction(&Receiver::Function1);
    pSender->Invoke();

    // コールバック関数を Receiver::Function2() に設定
    pSender->SetCallbackFunction(&Receiver::Function2);
    pSender->Invoke();

    delete pReceiver;
    delete pSender;
}