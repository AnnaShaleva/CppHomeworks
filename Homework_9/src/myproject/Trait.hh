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

template<> class Trait<std::string>
{
	public:
		static int GetSize(const std::string& source)
		{
			int result = 0;
			for(int i = 0; i < source.length(); i++)
				result += sizeof(source[i]);
			return result;
		}
};

template<> class Trait<My::User>
{
public:
	static int GetSize(const My::User& source)
	{
		int result = 0;
		result += sizeof(source.Id);
		result += Trait<std::string>::GetSize(source.Name);
		result += Trait<std::string>::GetSize(source.Surname);
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
		result += Trait<std::string>::GetSize(source.Name);
		for(const auto& user: source.Users)
			result += Trait<My::User>::GetSize(user);
		return result;
	}
};

