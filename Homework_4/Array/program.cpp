#include <iostream>
#include "MyArray.cpp"

int main()
{
	MyArray<int> m = MyArray<int>(1, 1);
	MyArray<int> n = MyArray<int>(1, 1);
	m(0,0) = 1;
	n(0,0) = 2;
	MyArray<int> sum = m+n;
	std::cout << "Sum: " << sum(0,0) << '\n';
	//std::cout << "m + n [0][0]:" << a;
	std::cout << "n-size of M: " << m.N() << '\n';
	m(0,0) = 4;
	std::cout << "Element (1,2): " << m(0,0) << '\n'; 
	//delete m;
	return 0;
};
