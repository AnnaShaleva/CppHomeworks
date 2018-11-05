#include "User.cpp"
#include <unordered_set>
#include <string>

class Group
{
public:
	std::string Name;
	int Id;
	std::unordered_set<My::User> Users;

	Group(std::string name, int id, const std::unordered_set<My::User>& users)
	{
		Name = name;
		Id = id;
		Users = users;
	}

	Group(const Group& g)
	{
		Name = g.Name;
		Id = g.Id;
		Users = g.Users;
	}
};

int main()
{
	auto users = std::unordered_set<My::User>{
		{1, "Anna", "Shaeva"},
		{2, "Ivan", "Petryakov"}
	};
	Group g = Group("405", 1, users);
	return 0;
}
