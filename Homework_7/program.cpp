#include <iostream>
#include "LineNumberBuffer.cpp"

int main()
{
	std::string s;
	std::string toWrite;
	std::streambuf* oldbuf = std::cout.rdbuf();
	LineNumberBuffer myBuffer{oldbuf};
	std::cout.rdbuf(&myBuffer);
	while(getline(std::cin, s))
	{
		toWrite += s + "\n";
	}
	std::cout << toWrite;
	std::cout.rdbuf(oldbuf);
	return 0;
}
