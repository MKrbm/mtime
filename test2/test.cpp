#include <iostream>
#include "mtime.hpp"
#include <cstdlib>
#include <iostream>
#include <random>

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
		return return_double(a);
	}

};

int hoge::return_double(int a){
	return a*a + x;
}

int main(int, char**) {
  // _mtime square = mtime_class;

	hoge foo2(2);

  auto foo2_mtime = _mtime2(&hoge::return_double,"return_double", foo2
                            ,"foo");

  std::cout << foo2_mtime(4) << std::endl;

  return 0;


  // std::cout << mtime_class_3.return_x() <<std::endl;
  // std::cout << mtime_class_3.x <<std::endl;


}
