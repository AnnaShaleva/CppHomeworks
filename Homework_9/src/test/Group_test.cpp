#include <myproject/User.hh>
#include <myproject/Group.hh>
#include <gtest/gtest.h>
#include <string>
#include <unordered_set>

TEST(Group_test, Create_group_test)
{
	//Arrange
	int id = 1;
	std::string name = "Math";
	My::User u1 = My::User(1, "Anna", "Shaleva");
	My::User u2 = My::User(2, "Ivan", "Petryakov");
	std::unordered_set<My::User> myUsers = { u1, u2 };
	
	//Act
	Group g = Group(1, "Math", myUsers);
	
	//Assert
	EXPECT_EQ(id, g.Id);
	EXPECT_EQ(name, g.Name);
	EXPECT_EQ(myUsers, g.Users);
}
