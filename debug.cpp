#include <iostream>
#include <mtime.hpp>
#include <cstdlib>
#include <iostream>
#include <random>
#include "MainConfig.h"

int add(int a, int b) {
  return a+b;
}

std::string sayhello(){
  return "hello";
}

int square(int a){
  return a*a;
}

void foo2(){
  std::cout<<"hi" <<std::endl;
}

void loop(){
  for (int i=0; i < 10000; i++) square(3);
  return;
}



class hoge {
public:
	typedef int hei;
	int x;
	hoge(int a) : x(a){}
	hoge * cp = this;

	int return_double(int a);
	

	int measure_func(int a){
		auto mtimer = mtime(hoge::return_double, *this);
		auto& return_double = mtimer;
		// mtimer(4); 
		print_2();
		return return_double(a);
	}

};

int hoge::return_double(int a){
	return a*a + x;
}

int main(int, char**) {
  // _mtime square = mtime_class;

	hoge foo2(2);
	std::cout << foo2.measure_func(4) << std::endl;

	// test_class test(&hoge::return_double,foo2);
	// std::cout << test.exec(3) << std::endl;
	// auto mtimer = mtime1(hoge::return_double, foo2);
	// std::cout << mtimer(3) << std::endl;

	// foo2::hei a=0;
	// std::cout << hoge::hei << std::endl;





  // auto mtime_class = mtime2(square);

  // for (int i=0; i < 10000; i++) mtime_class(3);

  // std::cout << mtime_class.mExeTime() << std::endl;
  // auto loop_class = mtime(loop);
  // loop_class();
  // std::cout << loop_class.mExeTime() << std::endl;

  // auto foo__ = mtime(foo2);

  // std::cout << mtime_class(3) <<std::endl;
  // std::cout << hello() <<std::endl;
  // foo__();


  // auto x = foo2();
  // static_assert(!, "void"); 
// 
  // auto foo2_ = mtime(foo2);
  // std::cout << decltype(foo2()) <<std::endl;

  // std::cout << mtime_class.return_x() <<std::endl;

  // auto mm = mtime(foo2);
  // mm();

  // int r;
  // auto begin = std::chrono::steady_clock::now();
  // auto block = mtime([]{
  //   for (int i=0; i < 1000000; i++) {
  //     rand() % 100;
  //   }
  // });
  // block();
  // std::cout << block.mExeTime()<< "[ms]" << std::endl; 
  // auto end = std::chrono::steady_clock::now();

  // std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;


  // std::mt19937 rand_src(static_cast <unsigned> (time(0)));
  // std::uniform_int_distribution<> dist(0, 10);

  // begin = std::chrono::steady_clock::now();
  // for (int i=0; i < 1000000; i++) r = dist(rand_src);; 
  // end = std::chrono::steady_clock::now();

  // std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;






  // // auto mtime_class_2 = mtime(foo);
  // // // std::cout << mtime_class_2.return_x() <<std::endl;

  // // auto mtime_class_3 = mtime(sub);
  // auto begin = std::chrono::steady_clock::now();
  // std::cout << "add(1,2) = " << add(1,2) <<std::endl;
  // auto end = std::chrono::steady_clock::now();

  // // auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
  // // std::cout << "exection time : " << ms << "[ms]"  << std::endl;

  // auto mtime_class_4 = mtime(add);
  // std::cout << mtime_class_4(3,3) <<std::endl;

  // auto mtime_class_5 = mtime(add);
  // std::cout << mtime_class_5(3,3) <<std::endl;
  return 0;


  // std::cout << mtime_class_3.return_x() <<std::endl;
  // std::cout << mtime_class_3.x <<std::endl;


}
