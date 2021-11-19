#include <iostream>
#include <vector>
#include <array>
#include <type_traits>

template <typename T, typename = int>
struct HasX : std::false_type { };

template <typename T>
struct HasX <T, typename T::type> : std::true_type { };



template <typename T>
auto print(T v) -> decltype(std::begin(v), void())  // (1)
{
    std::cout << "container" << std::endl;
}

template <typename T>
auto print(T []) -> void                            // (2)
{
    std::cout << "array" << std::endl;
}

template <typename T>
auto print(T v) -> decltype(v + 0, void())          // (3)
{
    std::cout << "value" << std::endl;
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


template <typename T, typename U>
void print2(T t, U x){
  // std::cout << typeid(U).name() << std::endl;
  // std::cout << "typeof x : " << typeid(x).name() << std::endl;
  std::cout << "2 is called" << std::endl;
}

template <typename T, typename U = int>
void print2(T t, typename U::type x){
  // std::cout << typeid(U).name() << std::endl;
  // std::cout << t << std::endl;
  std::cout << "1 is called" << std::endl;
}

template <typename T>
void print2(T t, typename T::type='c'){
  std::cout << "3 is called" << std::endl;
}


template<typename T, typename C = int>
class MyClass
{
public:
  T t;
  C c;
  MyClass(T t) :t(t), c(0){}
  MyClass(T x, C c) :t(t), c(c){}

  // template<typename C_ = C>
  // void print_c()
};


int main()
{
    std::vector<float>  a = { 0, 1, 2 };
    double b[3] = { 0, 1, 2 };
    std::array<int, 3> c = { 0, 1, 2 };
    int d = 0;
    struct { int x; int y; } e = { 0, 1 };
    struct CC {
      typedef int type;
      int x = 3;
    };

    print2(3,4);
    print2(CC());
    print2(3,CC());

    // CC cc = CC();
    std::cout << typeid(CC::type).name() << std::endl;
    std::cout << (HasX<CC>::value == true) << std::endl;
    std::cout << (HasX<int>::value == true) << std::endl;
  
    // CC::type aa = 3;

    MyClass myclass_1 = MyClass(3);
    MyClass myclass_2 = MyClass(3, "hi");


    return 0;
}