#include "MergeSort.hh"
#include <iostream>
#include <chrono>

int main()
{

	for(int i = 10; i < 1000000000; i = i * 10)
	{
		std::vector<int> v1;
		for (int j = 0; j < i; j++)
			v1.push_back(std::rand()%100);
		std::vector<int> v2 = v1;
		auto start1 = std::chrono::system_clock::now();
		MergeSort(v1.begin(), v1.end(), std::thread::hardware_concurrency());
		auto end1 = std::chrono::system_clock::now();
		auto start2 = std::chrono::system_clock::now();
		MergeSort(v2.begin(), v2.end(), 1);
		auto end2 = std::chrono::system_clock::now();
		std::cout << "Number of elements: " << i << std::endl;
		std::cout << "Parallel sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count() << " ms" << std::endl;
		std::cout << "Single thread sort: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << " ms" << std::endl;
		std::cout << "_______" << std::endl;
	}
	return 0;
}
