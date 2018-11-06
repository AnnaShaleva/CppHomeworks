#include <string>
#include <unordered_map>

namespace My
{
	class User
	{
public:
		int Id;
		std::string Name;
		std::string Surname;
public:
		User(int id, std::string name, std::string surname)
		{
			Id = id;
			Name = name;
			Surname = surname;
		}
		
		User(const User& user)
		{
			Id = user.Id;
			Name = user.Name;
			Surname = user.Surname;
		}

		bool operator==(const User& user) const
		{
			return (Id == user.Id
				&& Name == user.Name
				&& Surname == user.Surname);
		}
	};
}

namespace std
{
	template<>
	class hash<My::User>
	{
		public:
		std::size_t operator() (const My::User& x) const
		{
			return ((std::hash<int>()(x.Id)
				^ (std::hash<std::string>()(x.Name) << 1)) >> 1
				^ std::hash<std::string>()(x.Surname) << 1);
		}
	};
}

