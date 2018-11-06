#include "User.hh"
#include "Group.hh"
#include "Trait.hh"
#include <gtest/gtest.h>
#include <string>
#include <unordered_set>

TEST(Trait_test, Get_User_size_test)
{
	//Arrange
	auto user = My::User(2, "A", "B");

	//Act
	Trait<My::User>::GetSize(user);
	
	//Assert
	//?
}

TEST(Trait_test, Get_Group_size_test)
{
	//Arrange
	auto users = std::unordered_set<My::User>{
		{1, "Anna", "Shaeva"},
		{2, "Ivan", "Petryakov"}
	};
	auto g = Group(1, "405", users);
	
	//Act
	Trait<Group>::GetSize(g);

	//Assert
	//?
}

