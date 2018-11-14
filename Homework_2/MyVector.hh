#include <cstddef>

template <class T>
class MyVector
{
public:
	T* beginPointer;
	const size_t maxSize = 100;
	size_t currentSize;

public:
	explicit MyVector()
	{
		currentSize = 0;
		beginPointer = new T[maxSize];
	}

	explicit MyVector(size_t count, const T& value)
	{
		if(count <= maxSize)
		{
			currentSize = 0;
			beginPointer = new T[maxSize];	
			for (size_t i = 0; i < count; i++)
			{
				beginPointer[i] = value;
				currentSize ++;
			}
		}
	}

	explicit MyVector(size_t count)
	{
		if(count <= maxSize)
		{
			currentSize = 0;
			beginPointer = new T[maxSize];
			for(size_t i = 0; i < count; i++)
			{
				beginPointer[i] = T();
				currentSize++;
			}
		}
	}

	MyVector(const MyVector& other)
	{
		currentSize = 0;
		_Swap(other);	
	}

	MyVector(MyVector&& other)
	{
		currentSize = other.currentSize;
		beginPointer = other.beginPointer;
		other.beginPointer = nullptr;
		other.currentSize = 0;
	}

	MyVector& operator=(const MyVector& other)
	{
		if(this!= &other)
		{
			delete[] beginPointer;
			if(currentSize == other.currentSize)
				_Swap(other);
		}
		return *this;
	}
	
	MyVector& operator=(MyVector&& other)
	{
		if(this!= &other)
		{
			delete[] beginPointer;
			if(this.currentSize = other.currentSize)
				this.begiinPointer = other.beginPointer;
			other.beginPointer = nullptr;
			other.currentSize = 0;
		}
		return *this;
	}		

	~MyVector()
	{
		if(beginPointer)
			delete[] beginPointer;
	}

	const T& operator[](size_t pos) const
	{
		return beginPointer[pos];
	}
	
	T& operator[](size_t pos)
	{
		return beginPointer[pos];
	}
	
	T* Begin()
	{
		if(beginPointer)
		{
			return beginPointer;
		}
	}

	T* End()
	{
		if(beginPointer)
		{
			return &beginPointer[currentSize];
		}
	}

	size_t Size()
	{
		if(beginPointer)
		{
			return currentSize;
		}
	}

	void PushBack(const T& value)
	{
		if(currentSize < maxSize)
		{
			beginPointer[currentSize] = value;
			currentSize ++;
		}
	}

	void PushBack(T&& value)
	{
		if(currentSize < maxSize)
		{
			beginPointer[currentSize] = std::move(value);
			currentSize ++;
			value = T();
		}
	}

	void PopBack()
	{
		if(currentSize > 0)
		{
			beginPointer[currentSize - 1] = T();
			currentSize --;
		}
	} 

	void Swap(MyVector& other)
	{
		if(currentSize = other.currentSize)
		{
			for(size_t i = 0; i < currentSize; i++)
			{
				T temp = beginPointer[i];
				beginPointer[i] = other[i];
				other[i] = temp;
			}
		}
	}

	void Erase(int pos)
	{
		if(currentSize > 0)
			if(pos >= 0 && pos < currentSize)
			{
				for(int i = pos; i < currentSize - 1; i++)
					beginPointer[i] = beginPointer[i + 1];
				beginPointer[currentSize - 1] = T();
				currentSize --;
			}
	}

	void Erase(int first, int last)
	{
		if(currentSize > 0)
			if(first <= last && first >= 0 && last <= currentSize)
			{
				if(currentSize - last < last - first)
				{
					for(int i = first; i < first + (currentSize-last); i++)
						beginPointer[i] = beginPointer[i+(last-first)];
					for(int i = first+(currentSize-last); i < currentSize; i++)
						beginPointer[i] = T();
				}
				else
				{
					for(int i = first; i < currentSize - (last-first); i++)
						beginPointer[i] = beginPointer[i+(last-first)];
					for(int i = currentSize-(last-first); i < currentSize; i++)
						beginPointer[i] = T();
				}
				currentSize = currentSize - (last - first);
			}
	}

private:

	void _Swap(const MyVector& other)
	{
		currentSize = 0;
		beginPointer = new T[maxSize];
		for(size_t i = 0; i < other.currentSize; i++)
		{
			beginPointer[i] = other[i];
			currentSize++;
		}
	}
		
};
