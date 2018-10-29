#include <iostream>

class LineNumberBuffer: public std::streambuf
{
	std::streambuf* old;
       	std::string str;
	int lineCount;
public:
	explicit LineNumberBuffer(std::streambuf* b) : old(b)
	{
		lineCount = 1;
	}
protected:
	int_type overflow(int_type c) override
       	{		
		return old->sputc(c);
	}
	std::streamsize xsputn(const char* s, std::streamsize n) override
	{
		str += std::to_string(lineCount) + " ";	
		std::string oldString;
		oldString.assign(s, n);
		for (int i = 0; i < oldString.length() - 1; i++)
		{
			char& ch = oldString[i];
			str += ch;
			if (ch == '\n')
			{
				 
				lineCount++;			
				str+= std::to_string(lineCount) + " ";
			}			
		}
		str += oldString[oldString.length() - 1];
		return old->sputn(str.data(), str.length());
	}

};

