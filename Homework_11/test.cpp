#include <iostream>
#include "MyThread.hh"

int MyFoo(void*)
{
	std::cout << "Hello, world!" << std::endl;
}

int main()
{
	std::cout << "1 join" << std::endl;
	auto t1 = MyThread(MyFoo); 
	std::cout << "1 join" << std::endl;
	t1.join();

	std::cout << "1 join" << std::endl;

	auto t2 = MyThread();
	std::cout << t2.get_id() << std::endl;
	std::cout << "t2 - joinable: " << t2.joinable() << std::endl;
	
	auto t3 = MyThread(MyFoo);
	std::cout << t3.get_id() << std::endl;

	t2 = std::move(t3);

	std::cout << "t2 - joinable: " << t2.joinable() << std::endl;
	std::cout << t2.get_id() << std::endl;

		
	t2.join();
	std::cout << "t2 - ojoinable: " << t2.joinable() << std::endl;
	std::cout << t2.get_id() << std::endl;	

	return 0;
};
