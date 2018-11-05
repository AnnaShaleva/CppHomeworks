#include "User.cpp"
#include "Group.cpp"
#include <iostream>

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

int main()
{
	auto users = std::unordered_set<My::User>{
		{1, "Anna", "Shaeva"},
		{2, "Ivan", "Petryakov"}
	};
	auto g = Group("405", 1, users);
	std::cout << Trait<Group>::GetSize(g) << std::endl;
	auto user = My::User(2, "A", "B");
	std::cout << Trait<My::User>::GetSize(user);
	return 0;
}

