template <class T>
class MyArray
{
	T** _array = nullptr;
	int _n;
	int _m;

public:
	int N() const
	{
		return _n;
	}

	int M() const
	{
		return _m;
	}

	MyArray(int n, int m)
	{
		_array = new T*[n];
		for(int i = 0; i < n; i++)
		{
			_array[i] = new T[m];
		}
		_n = n;
		_m = m;
	}

	~MyArray()
	{
		if (_array)
		{
			for (int i = 0; i < _n; i++)
			{
				delete [] _array[i];
			}
			delete [] _array;
		}
	}	

	T& operator()(int i, int j) const
	{
		if (i < _n && j < _m)
		{
			T& result = _array[i][j];
			return result;
		}
		throw std::out_of_range("Index is out of range.");
	}

	MyArray operator+(const MyArray& a)
	{
		int n = a.N();
		int m = a.M();
		if (_n == n && _m == m)
		{
			MyArray result = MyArray(n, m);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					result(i, j) = _array[i][j] + a(i, j);
				}
			return result;
		}
		throw std::out_of_range("Index is out of range.");
	}

	MyArray operator-(const MyArray& a)
	{
		int n = a.N();
		int m = a.M();
		if (_n == n && _m == m)
		{
			MyArray result = MyArray(n, m);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					result(i, j) = _array[i][j] - a(i, j);
				}
			return result;
		}
		throw std::out_of_range("Index is out of range.");
	}

	MyArray operator*(const MyArray& a)
	{
		int n = a.N();
		int m = a.M();
		if (_n == n && _m == m)
		{
			MyArray result = MyArray(n, m);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					result(i, j) = _array[i][j] * a(i, j);
				}
			return result;
		}
		throw std::out_of_range("Index is out of range.");
	}
};

		
