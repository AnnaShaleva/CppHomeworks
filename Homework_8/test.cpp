#include "MergeSort.hh"
#include <iostream>

int main()
{
	std::vector<int> v1{8, 4, 1, 9, 16, 3};
	MergeSort(v1.begin(), v1.end(), std::thread::hardware_concurrency());
	std::vector<int> v2{8, 4, 1, 9, 16, 3};
	MergeSort(v2.begin(), v2.end(), 1);
	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << std::endl;
	}	
	return 0;
}
