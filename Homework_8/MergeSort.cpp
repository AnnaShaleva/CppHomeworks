#include <vector>
#include <iostream>
#include <thread>

template <class InputIterator>//, class OutputIterator>
void Merge(InputIterator l, InputIterator m, InputIterator r)
{
	typedef typename std::iterator_traits<InputIterator>::value_type T;
	std::vector<T> result;
	InputIterator L = l;
	InputIterator R = m;
       	while(L < m && R < r)
	{
		if(*L <= *R)
		{
			result.push_back(*L);
			L++;
		}
		else
		{
			result.push_back(*R);
			R++;
		}
	}
	while(L < m)
	{
		result.push_back(*L);
		L++;
	}
	while(R < r)
	{
		result.push_back(*R);
		R++;
	}
	std::copy(result.begin(), result.end(), l);
}
template <class InputIterator>//, class OutputIterator>
void MergeSort(InputIterator l, InputIterator r, int threadNumber)
{
	if (l+1 < r)
	{
		InputIterator m = l + (r - l) / 2;
		if (threadNumber > 1)
		{
			std::thread t(MergeSort<InputIterator>, l, m, threadNumber - 2);
			MergeSort(m, r, threadNumber - 2);
			t.join();
		}
		else
		{
			MergeSort(l, m, 0);
			MergeSort(m, r, 0);
		}
		Merge(l, m, r);
	}
}
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
	
}
