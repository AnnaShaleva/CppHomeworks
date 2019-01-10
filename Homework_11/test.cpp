#include <iostream>
#include "MyThread.hh"

int MyFoo(void*)
{
	std::cout << "Hello, world!" << std::endl;
}

int main()
{
	auto t1 = MyThread(MyFoo); 
	t1.join();
	return 0;
};
