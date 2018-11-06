#include "User.hh"
#include <gtest/gtest.h>
#include <string>
#include <unordered_set>
#include <unordered_map>

TEST(User_test, Create_user_test)
{
	//Arrange
	int id = 1;
	std::string name = "Anna";
	std::string surname = "Shaleva";

	//Act
	My::User user = My::User(1, "Anna", "Shaleva");
	
	//Assert
	EXPECT_EQ(id, user.Id);
	EXPECT_EQ(name, user.Name);
	EXPECT_EQ(surname, user.Surname);
}

TEST(User_test, Equals_operator_test)
{
	//Arrange
	My::User u1 = My::User(1, "Ivan", "Petryakov");
	My::User u2 = My::User(1, "Ivan", "Petryakov");
	bool expectedResult = true;

	//Act
	bool result = (u1 == u2);

	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(User_test, Create_unordered_set_test)
{
	//Arrange
	My::User u1 = My::User(1, "Anna", "Shaleva");
	My::User u2 = My::User(2, "Ivan", "Petryakov");

	//Act
	std::unordered_set<My::User> myUsers = { u1, u2 };
	
	//Assert
	//?
}

TEST(User_test, Create_unordered_map_test)
{
	//Arrange
	My::User u1 = My::User(1, "Anna", "Shaleva");
	My::User u2 = My::User(2, "Ivan", "Petryakov");

	//Act
	std::unordered_map<My::User, std::string> myUsers = { 
		{u1, "Cat"},
		{u2, "Dog"}};
	
	//Assert
	//?
}


