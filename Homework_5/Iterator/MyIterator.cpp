#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

template <class T, class charT=char, class traits=std::char_traits<charT> >
class MyIterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
{
	std::basic_ostream<charT, traits>* outStream;
	int N;
	const charT* delim;
private:
	int _symbolNum;
public:
	MyIterator(std::basic_ostream<charT, traits>& s, int n) : outStream(&s)
	{
		N = n;
		_symbolNum = 0;
	}
	
	MyIterator(std::basic_ostream<charT, traits>& s, const charT* delimiter, int n) : outStream(&s), delim(delimiter)
	{
		N = n;
		_symbolNum = 0;
	}

	~MyIterator()
	{
	}

	MyIterator& operator=(const T& value)
	{
		_symbolNum++;
		if (outStream)
			if (_symbolNum % N == 0)
			{
				*outStream << value;
				if (delim != 0)
					*outStream << delim;
				_symbolNum = 0;
			}
		return *this;
	}

	MyIterator& operator*()
	{
		return *this;
	}

	MyIterator& operator++()
	{
		return *this;
	}

	MyIterator& operator++(int i)
	{
		return *this;
	}
};

int main()
{
	std::vector<int> myVector;
	for (int i = 0; i < 10; ++i)
		myVector.push_back(i*10);

	MyIterator<int> outIterator(std::cout, ", ", 5);
	std::copy(myVector.begin(), myVector.end(), outIterator);
	return 0;
}
