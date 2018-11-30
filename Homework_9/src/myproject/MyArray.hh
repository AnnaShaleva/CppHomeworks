#include <stdexcept>

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

	MyArray(const MyArray& source)
	{
		int n = source.N();
		int m = source.M();
		_array = new T*[n];
		for(int i = 0; i < n; i++)
		{
			_array[i] = new T[m];
			for(int j = 0; j < m; j++)
				_array[i][j] = source(i,j);
		}
		_n = n;
		_m = m;
	};

	MyArray(int n, int m, const T** source)
	{		
		_array = new T*[n];
		for(int i = 0; i < n; i++)
		{
			_array[i] = new T[m];
			for (int j = 0; j < m; j++)
				_array[i][j] = source[i][j];
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

	bool operator==(const MyArray& array) const
	{
		if (!(array.N() == _n && array.M() == _m))
			return false;
		for (int i = 0; i < _n; i++)
			for (int j = 0; j < _m; j++)
				if (_array[i][j] != array(i, j))
					return false;
		return true;
	}
		

	T& operator()(int i, int j)
	{
		if (i < _n && j < _m)
		{
			T& result = _array[i][j];
			return result;
		}
		throw std::out_of_range("Index is out of range.");
	}
	
	T operator()(int i, int j) const
	{
		if (i < _n && j < _m)
		{
			T result = _array[i][j];
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
	
	MyArray operator/(const MyArray& a)
	{
		int n = a.N();
		int m = a.M();
		if (_n == n && _m == m)
		{
			MyArray result = MyArray(n, m);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					result(i, j) = _array[i][j] / a(i, j);
				}
			return result;
		}
		throw std::out_of_range("Index is out of range.");
	}

	MyArray<bool> operator&&(const MyArray& a)
	{
		int n = a.N();
		int m = a.M();
		if (_n == n && _m == m)
		{
			MyArray<bool> result = MyArray<bool>(n, m);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					result(i, j) = _array[i][j] && a(i, j);
				}
			return result;
		}
		throw std::out_of_range("Index is out of range.");
	}

	MyArray<bool> operator||(const MyArray& a)
	{
		int n = a.N();
		int m = a.M();
		if (_n == n && _m == m)
		{
			MyArray<bool> result = MyArray<bool>(n, m);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					result(i, j) = _array[i][j] || a(i, j);
				}
			return result;
		}
		throw std::out_of_range("Index is out of range.");
	}

	MyArray<bool> operator!()
	{
		MyArray<bool> result = MyArray<bool>(_n, _m);
		for (int i = 0; i < _n; i++)
			for (int j = 0; j < _m; j++)
			{
				result(i, j) = !_array[i][j];
			}
		return result;
	}
public:
	class MyMaskedArray
	{
		MyArray&  _sourceArray;
		const MyArray<bool>& _mask;

		public:	

		MyMaskedArray(MyArray& array, const  MyArray<bool>& mask)
			: _sourceArray(array), _mask(mask)
		{
		}
	
		~MyMaskedArray()
		{
		}		

		void operator=(T value)
		{
			for(int i = 0; i < _sourceArray.N(); i++)
				for (int j = 0; j < _sourceArray.M(); j++)
					if(_mask(i,j))
						_sourceArray(i,j) = value;
		}
	};

	MyMaskedArray operator()(const MyArray<bool>& mask) 
	{
		int n = mask.N();
		int m = mask.M();
		if (_n == n && _m == m)
		{
			MyMaskedArray result = MyMaskedArray(*this, mask);
			return result;
		}
		throw std::out_of_range("Index is out of range.");
	}
};
