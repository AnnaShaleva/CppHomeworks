#include <cstddef>

template <class T>
class MyVector
{
	T* beginPointer;
	const size_t maxSize = 10;
	size_t currentSize;

public:
	explicit MyVector() : 
		currentSize(0),
		beginPointer(new T[maxSize])
	{
	}

	explicit MyVector(size_t count, const T& value) : 
		currentSize(0),
		beginPointer(new T[maxSize])
	{
		if(count <= maxSize)
		{
			for (size_t i = 0; i < count; i++)
			{
				beginPointer[i] = value;
				currentSize++;
			}
		}
	}

	explicit MyVector(size_t count) : 
		currentSize(0),
		beginPointer(new T[maxSize])
	{
		if(count <= maxSize)
		{
			for(size_t i = 0; i < count; i++)
			{
				beginPointer[i] = T();
				currentSize++;
			}
		}
	}

	MyVector(const MyVector& other) :
		currentSize(0),
		beginPointer(new T[maxSize])
	{
		for(size_t i = 0; i < other.currentSize; i++)
		{
			beginPointer[i] = other[i];
			currentSize++;
		}
	}

	MyVector(MyVector&& other) :
		currentSize(0),
		beginPointer(nullptr)
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
			Swap(other);
		}
		return *this;
	}
	
	MyVector& operator=(MyVector&& other)
	{
		if(this!= &other)
		{
			delete[] beginPointer;
			Swap(other);
			delete[] other.beginPointer;
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
			return *(beginPointer[currentSize]);
		}
	}

	size_t Size()
	{
		if(beginPointer)
		{
			return currentSize;
		}
	}

private:

	void Swap(MyVector&& other)
	{
		currentSize = other.currentSize;
		beginPointer = new T[maxSize];
		for(size_t i = 0; i < currentSize; i++)
		{
			beginPointer[i] = other[i];
		}
	}
		


};
