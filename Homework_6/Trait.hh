//#include "User.hh"
//#include "Group.hh"

template <class T>
class Trait
{
public:
	static int GetSize(T& source)
	{
		return sizeof(source);
	}
};

template<> class Trait<My::User>
{
public:
	static int GetSize(My::User& source)
	{
		return sizeof(source);
	}
};

template<> class Trait<Group>
{
public:
	static int GetSize(Group& source)
	{
		//TODO: How to define the size for this element?
		return sizeof(source);
	}
};

