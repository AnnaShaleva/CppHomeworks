int Rotate(std::vector<int>& source, int degree)
{
	int times = degree / 90;
	int quoter = times % 4;
	if(times < 0)
		quoter += 4;
	if(source.size() != 2)
	{
		return -1;
	}
	switch(quoter)
	{
	case 0:
	{
		return 0;
	}	
	case 1:
	{
		int x = source[0];
		source[0] = source[1];
		source[1] = -x;
		return 0;
	}
	case 2:
	{
		source[0] = -source[0];
		source[1] = -source[1];
		return 0;
	}
	case 3:
	{
		int x = source[0];
		source[0] = -source[1];
		source[1] = x;
		return 0;
	}
	}
}

