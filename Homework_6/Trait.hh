//#include "User.hh"
//#include "Group.hh"

template <class T>
class Trait
{
public:
	static int GetSize(const T& source)
	{
		return sizeof(source);
	}
};

template<> class Trait<My::User>
{
public:
	static int GetSize(const My::User& source)
	{
		int result = 0;
		result += sizeof(source.Id);
		result += sizeof(source.Name);
		result += sizeof(source.Surname);
		return result;
	}
};

template<> class Trait<Group>
{
public:
	static int GetSize(Group& source)
	{
		int result = 0;
		result += sizeof(source.Id);
		result += sizeof(source.Name);
		for(const auto& user: source.Users)
			result += Trait<My::User>::GetSize(user);
		return result;
	}
};

