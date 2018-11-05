#include <vector>
#include <iostream>

template <class InputIterator, class OutputIterator>
void Merge(OutputIterator result, InputIterator array, int l, int m, int r)
{
	InputIterator L = l_init;
	InputIterator R = m_init;
	InputIterator n1 = m_init - l_init + 1;
	InputIterator n2 = r_init - m_init;
	while (L < n1  && R < n2)
	{
		if (*L <= *R)
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
