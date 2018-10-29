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
		std::cout << "Finalizer starts. Fill: " << _stream.fill() << '\n';
		_stream.flags(_flags);
		_stream.fill(_fillCh);
		std::cout << "Finalizer. Fill: " << _stream.fill()<< '\n';
	}
};

int main()
{
	std::cout.fill('-');
	std::cout.width(7);
	std::cout << "Mur" << '\n';
	std::cout << "Mur" << '\n';
	MyGuard* pt = new MyGuard(std::cout);
	std::cout.fill('+');
	std::cout.width (5);
	std::cout << "Mur" << '\n';
	delete pt;
	std::cout << "Mur" << '\n';
	return 0;
}
