#include <iostream>

struct MyGuard
{
	std::ostream& _stream;
	std::ios_base::fmtflags _flags;
	char _fillCh;

	MyGuard(std::ostream& stream) : _stream(stream)
	{
		_flags = stream.flags();
		_fillCh = stream.fill();
		std::cout << "Constructor. Fill: " << stream.fill() << '\n';
	}
	
	~MyGuard()
	{
		_stream.flags(_flags);
		_stream.fill(_fillCh);
	}
};

