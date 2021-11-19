/* 

__mtime__ class
- It enables measure execution time of any functions.
- It holds the information of how many times the function is called.

*/

#ifndef __mtime__
#define __mtime__

#define print_2() std::cout << __PRETTY_FUNCTION__ << std::endl;

#define mtime1(Func) _mtime1(Func, #Func)
#define mtime2(Func, Obj) _mtime2(&Func, #Func, Obj, __FUNCTION__)

#define GET_MACRO(_1,_2,NAME,...) NAME
#define mtime(...) GET_MACRO(__VA_ARGS__, mtime2, mtime1)(__VA_ARGS__)
// #define FOO2(a, b) printf("hello world2 %d %d",a,b)
// #define FOO3(a,b,c) printf("hello world2 %d %d %d ",a,b,c)

// #include "base.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <numeric>


typedef std::vector<int> vint;
typedef std::vector<std::string> vstring;
typedef std::vector< std::vector<long> > vvlong;

class base_mtime{
public:
  // static int x;  
  static vint couts;
  static vstring name_list;
  static vvlong mt_list;
};



// Primary mtime class template. This is called for member function.
// We need to specify the class of the member function.
template <typename MFP, class C>
class _mtime2 : public base_mtime{
private:

  C* pHandle; // poiter to class 
  MFP fp;// pointer to member function

  int index;
  std::string func_name = "default function name";
  std::chrono::steady_clock::time_point begin;
  std::chrono::steady_clock::time_point end;


public:
  _mtime2(MFP FP, std::string func_name_, C& handle, std::string class_name_)
  :fp(FP), pHandle(&handle)
  {

    func_name = class_name_ + "::" + func_name_;
    std::string key = func_name;
    auto it = std::find(name_list.begin(), name_list.end(), key);


    if (it == name_list.end()) {
      std::cout << "add new function : " << func_name << std::endl;
      name_list.push_back(func_name);
      couts.push_back(0);
      mt_list.push_back(std::vector<long>());
      index = couts.size()-1;
    }else{
      index = std::distance(name_list.begin(), it);
      std::cout << "function already in used" << std::endl;
    }

  }
  template <typename... Args>
  auto operator()(Args... args){
    return operator_(fp, pHandle, args...);
  }

  template <typename RET, typename... Args>
  auto operator_(RET(C::*func_)(Args...), C* pHandle, Args... args){
    begin = std::chrono::steady_clock::now();
    auto r = (pHandle->*func_)(args...);
    end = std::chrono::steady_clock::now();
    auto mrs = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    couts[index] += 1;
    mt_list[index].push_back(mrs);
    return r;
  }


  double mExeTime(){
    double mrs = (double) std::accumulate(mt_list[index].begin(), mt_list[index].end(), 0);

    int division = 1E6;

    return mrs/division;
  }
  
};

// secondary mtime class template. This is called for non-member function
template<typename F>
class _mtime1 : public base_mtime{
private:

  std::string func_name;
  F func;
  int index;
  std::chrono::steady_clock::time_point begin;
  std::chrono::steady_clock::time_point end;


public:

  _mtime1(F func_, std::string func_name_)
  :func(func_), func_name(func_name_)
  {
    std::string key = func_name;
    auto it = std::find(name_list.begin(), name_list.end(), key);

    // std::cout << (it != name_list.end()) << std::endl;

    if (it == name_list.end()) {
      std::cout << "add new function : " << func_name << std::endl;
      name_list.push_back(func_name);
      couts.push_back(0);
      mt_list.push_back(std::vector<long>());
      index = couts.size()-1;
    }else{
      index = std::distance(name_list.begin(), it);
      std::cout << "function already in used" << std::endl;
    }

  }
  template <typename... Args>
  auto operator()(Args... args){
    return operator_(func, args...);
  }

  template <typename RET, typename... Args>
  auto operator_(RET(*func_)(Args...), Args... args){
    begin = std::chrono::steady_clock::now();
    auto r = func(args...);
    end = std::chrono::steady_clock::now();
    auto mrs = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    couts[index] += 1;
    mt_list[index].push_back(mrs);
    return r;
  }

  template <typename... Args>
  void operator_(void (*func_)(Args...), Args... args){
    begin = std::chrono::steady_clock::now();
    func(args...);
    end = std::chrono::steady_clock::now();
    auto mrs = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    couts[index] += 1;
    mt_list[index].push_back(mrs);
    return;
  }

  double mExeTime(){
    double mrs = (double) std::accumulate(mt_list[index].begin(), mt_list[index].end(), 0);

    int division = 1E6;

    return mrs/division;
  }
  
};






template<typename MFP, typename C>
class test_class : public base_mtime{
private:

  C* pHandle; //pointer to object
  MFP fp;

public:
  test_class(MFP FP, C& handle)
  :fp(FP), pHandle(&handle){}

  int exec(int a){
    return (pHandle->*fp)(a);
  }
};

#endif