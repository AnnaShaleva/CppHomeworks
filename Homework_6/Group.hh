#include <unordered_set>
#include <string>

class Group
{
public:
	int Id;
	std::string Name;
	std::unordered_set<My::User> Users;

	Group(int id, std::string name, const std::unordered_set<My::User>& users)
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


