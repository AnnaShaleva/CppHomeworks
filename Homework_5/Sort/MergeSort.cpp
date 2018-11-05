#include <vector>
#include <iostream>

template <class InputIterator, class OutputIterator>
void Merge(OutputIterator result, InputIterator array, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	InputIterator L = array + l;
	InputIterator R = array + m + 1;

	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			std::cout << "Bla" << std::endl;
			result[k] = L[i];
			i++;
		}
		else
		{
			result[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1)
	{
		result[k] = L[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		result[k] = R[j];
		j++;
		k++;
	}
}
	/*
	std::cout << "Merge:" << std::endl;
	std::cout << "L = " << *l_init << std::endl;
	std::cout << "M = " << *m_init << std::endl;
	std::cout << "R = " << *r_init << std::endl;
	InputIterator L = l_init;
	InputIterator R = m_init++;
	InputIterator n1 = m_init++;
	InputIterator n2 = r_init++;
	while (L < n1  && R < n2)
	{
		if (*L < *R)
		{
			*result = *L;
			result ++;
			L++;
		}
		else
		{
			*result = *R;
			result++;
			R++;
		}
	}
	while (L < n1)
	{
		*result = *L;
		result++;
		L++;
	}
	while (R < n2)
	{
		*result = *R;
		result++;
		R++;
	}
}
	
	std::cout << "Merge" << std::endl;
	std::cout << "l = " << *l << std::endl;
	std::cout << "m = " << *m << std::endl;
	std::cout << "r = " << *r << std::endl;
	auto n1 = m - l + 1;
	auto n2 = r - m;

	InputIterator left, right;

	InputIterator i, j, k;

	while(i < n1 && j < n2)
	{
		if (*l <= *(m+1))
		{
			*result[k] = *l
	while(l != m)
	{

	InputIterator l = l_init;
	InputIterator m = m_init;
	InputIterator r = r_init;
	while(l < m && m < r)
	{
		std::cout << "While l < m && m < r" << std::endl;
		if (*l < *m)
		{
			*result = *l;
			result++;
			l++;
		}
		else
		{
			*result = *m;
			result++;
			m++;
		}
	}
	while(l < m)
	{
		std::cout << "While l < m" << std::endl;
		*result = *l;
		result++;
		l++;
	}
	while(m < r)
	{
		std::cout << "While m < r" << std::endl;
		*result = *m;
		result++;
		m++;
	}
}
*/
template <class InputIterator, class OutputIterator>
void MergeSort(OutputIterator result, InputIterator array, int l, int r)
{
	//std::cout << "Merge sort start" << std::endl;
	//std::cout << "l = " << *l << std::endl;
	//std::cout << "r = " << *r << std::endl;
	if (l < r)
	{
		int m = l + (r - l) / 2;
		//std::cout << "m = " << *m << std::endl;
		MergeSort(result, array, l, m);
		MergeSort(result, array, m + 1, r);
		Merge(result, array, l, m, r);

	}
}
int main()
{
	std::vector<int> v{8, 4, 1, 9, 16, 3};
	std::vector<int> result(v.size());
	MergeSort(result.begin(), v.begin(), 0, v.size() - 1);
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	}	
	return 0;
}
