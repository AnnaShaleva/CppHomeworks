#include "MyVector.hh"
#include <iostream>

int main()
{
	MyVector<int> v = MyVector<int>();
	auto a = MyVector<int>(2, 4);
	//auto b = MyVector<int>(a);
	std::cout << a.Size();
	return 0;
}
