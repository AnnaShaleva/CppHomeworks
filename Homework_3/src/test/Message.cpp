#include <iostream>
#include <stdexcept>

void Message(std::ostream& stream, const char* str)
{
	do
	{
		if (str[0] == '%')
		{
			//define the behavior in this case
			throw invalid_argument("There are too much '%' simbols.");
		}
		else
		{
			stream << str[0];
		}
	}
	while (*str++);
}

template <class Head>
void Message(std::ostream& stream, const char* str, Head head)
{
	while (str[0] != '%')
	{
		if (str[0] != '\0')
		{
			stream << str[0];
			*str++;
		}
		else return;
    	}
	stream << head;
	*str++;
	Message(stream, str);
}

template <class Head, class ... Tail>
void Message(std::ostream& stream, const char* str, Head head, Tail ... tail)
{
    while (str[0] != '%')
    {
	    if (str[0] != '\0')
	    {
		    stream << str[0];
		    *str++;
	    }
	    else return;
    }
    stream << head;
    *str++;
    Message(stream, str, tail...);
}
