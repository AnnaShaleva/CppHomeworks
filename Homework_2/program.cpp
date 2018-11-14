#include <fstream>
#include <iostream>
#include "MyVector.hh"
#include <random>
#include <algorithm>

int main()
{
	auto v = MyVector<std::ofstream>();
	
	v.PushBack(std::ofstream("a.txt", std::ofstream::out));
	v.PushBack(std::ofstream("b.txt", std::ofstream::out));
	v.PushBack(std::ofstream("c.txt", std::ofstream::out));
	v.PushBack(std::ofstream("d.txt", std::ofstream::out));
	v.PushBack(std::ofstream("e.txt", std::ofstream::out));
	
	std::cout << v.Size();
	
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(v.Begin(), v.End(), g);

	for(int i = 0; i < 5; i++)
	{
		v[i] << i;
		v[i].close();
	}

	return 0;
}


