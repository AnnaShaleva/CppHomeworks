#include <vector>
#include <iostream>

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
void MergeSort(InputIterator l, InputIterator r)
{
	if (l+1 < r)
	{
		InputIterator m = l + (r - l) / 2;
		MergeSort(l, m);
		MergeSort(m, r);
		Merge(l, m, r);
	}
}
int main()
{
	std::vector<int> v{8, 4, 1, 9, 16, 3};
	MergeSort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}	
	return 0;
}
