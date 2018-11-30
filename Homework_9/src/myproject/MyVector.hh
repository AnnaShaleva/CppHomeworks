#include <cstddef>
#include <utility>

template <class T>
class MyVector
{
public:
	T* beginPointer;
	size_t maxSize;
	size_t currentSize;

public:
	explicit MyVector()
	{
		currentSize = 0;
		maxSize = 10;
		beginPointer = new T[maxSize];
	}

	explicit MyVector(size_t count, const T& value)
	{
		maxSize = 10;
		while(count > maxSize)
			maxSize = maxSize * 10;
		currentSize = 0;
		beginPointer = new T[maxSize];	
		for (size_t i = 0; i < count; i++)
		{
			beginPointer[i] = value;
			currentSize ++;
		}
	}

	explicit MyVector(size_t count)
	{
		maxSize = 10;
		while(count > maxSize)
			maxSize = maxSize * 10;
		currentSize = 0;
		beginPointer = new T[maxSize];
		for(size_t i = 0; i < count; i++)
		{
			beginPointer[i] = T();
			currentSize++;
		}
	}

	MyVector(const MyVector& other)
	{
		maxSize = other.maxSize;
		currentSize = 0;
		_Swap(other);	
	}

	MyVector(MyVector&& other)
	{
		maxSize = other.maxSize;
		currentSize = other.currentSize;
		beginPointer = other.beginPointer;
		other.maxSize = 0;
		other.beginPointer = nullptr;
		other.currentSize = 0;
	}

	MyVector& operator=(const MyVector& other)
	{
		if(this!= &other)
		{
			delete[] beginPointer;
			maxSize = other.maxSize;
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
			maxSize = other.maxSize;
			if(this.currentSize = other.currentSize)
				this.beginPointer = other.beginPointer;
			other.beginPointer = nullptr;
			other.currentSize = 0;
			other.maxSize = 0;
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
		return beginPointer;
	}

	T* End()
	{
		return &beginPointer[currentSize];
	}

	size_t Size()
	{
		return currentSize;
	}
	
	void OnOversize()
	{
		maxSize = maxSize * 10;
		T* temp = new T[maxSize];
		for (int i = 0; i < currentSize; i++)
			temp[i] = std::move(beginPointer[i]);
		delete[] beginPointer;
		beginPointer = temp;
	}

	void PushBack(const T& value)
	{
		if(currentSize >= maxSize)
		{
			OnOversize();
		}
		beginPointer[currentSize] = value;
		currentSize ++;
	}

	void PushBack(T&& value)
	{
		if(currentSize >= maxSize)
			OnOversize();
		beginPointer[currentSize] = std::move(value);
		currentSize ++;
		value = T();
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
