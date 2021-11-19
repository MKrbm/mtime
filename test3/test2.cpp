#include <iostream>
#include <vector>
#include <array>

template <typename T>
auto print(T v) -> decltype(std::begin(v), void())  // (1)
{
    std::cout << "container : " << std::endl;
}

template <typename T>
auto print(T* v) -> void                            // (2)
{

    std::cout << "array array[0] : " << v[0] << std::endl;
}

template <typename T>
auto print(T v) -> decltype(v + 0, void())          // (3)
{
    std::cout << "value : " << v << std::endl;
}

#if 0
// (3)を次のように書くとコンパイルエラー
template <typename T>
auto print(T t) -> void
{
    std::cout << "value" << std::endl;
}
#endif

template<>
auto print<float>(float v) -> void                  // (4)
{
    std::cout << "value(specialized for float)" << std::endl;
}

void print(...)                                     // (5)
{
    std::cout << "other type" << std::endl;
}


template <typename T, typename U = int>
void print2(T t)
{
    std::cout << typeid(U).name() << std::endl;
    std::cout << "Iterator available." << std::endl;
}

template <typename T, typename U = int>
void print2(T t, U u)
{
    std::cout << typeid(U).name() << std::endl;
    std::cout << "No iterator." << std::endl;
}



int main()
{
    std::vector<float>  a = { 0, 1, 2 };
    double b[3] = { 0, 1, 2 };
    std::array<int, 3> c = { 0, 1, 2 };
    int d = 0;
    struct { int x; int y; } e = { 0, 1 };

    // hoge foo = hoge(2,3);
    // hoge foo2 = hoge(2);
    auto dd = std::is_reference<int>::value;

    // std::cout << a <<std::endl;


    print2(1);
    print2(1,"a");

    



    return 0;
}