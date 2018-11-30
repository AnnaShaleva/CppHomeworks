struct MyGuard
{
	std::ostream& _stream;
	std::ios_base::fmtflags _flags;
	char _fillCh;
	int _width;

	MyGuard(std::ostream& stream) : _stream(stream)
	{
		_flags = stream.flags();
		_fillCh = stream.fill();
		_width = stream.width();
	}
	
	~MyGuard()
	{
		_stream.flags(_flags);
		_stream.fill(_fillCh);
		_stream.width(_width);
	}
};

