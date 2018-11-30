#include <myproject/Message.hh>
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

TEST(Message_test, Correct_out_with_several_arguments_test)
{
	//Arrange
	std::stringstream stream;
	std::string expectedResult = "Hello, my beautiful world! 5";
	std::string result;

	//Act
	Message(stream, "Hello, % % world! %", "my", "beautiful", 5);
	result = stream.str();

	//Assert
	EXPECT_EQ(expectedResult, result);// << "Strings are not equal";
}

TEST(Message_test, Correct_out_with_extra_arguments_test)
{
	//Arrange
	std::stringstream stream;
	std::string expectedResult = "Hello, my world!";
	std::string result;

	//Act
	Message(stream, "Hello, % world!", "my", "beautiful", 5);
	result = stream.str();

	//Assert
	EXPECT_EQ(expectedResult, result) << "Strings are not equal";
}

TEST(Message_test, Correct_out_Different_arguments_types_case_test)
{
	//Arrange
	std::stringstream stream;
	std::string expectedResult = "A 1 Hello 0";
	std::string result;

	//Act
	Message(stream, "% % % %", 'A', 1, "Hello", false);
	result = stream.str();

	//Assert
	EXPECT_EQ(expectedResult, result) << "Strings are not equal";
}

TEST(Message_test, Exception_with_lack_of_arguments_No_arguments_case_test)
{
	//Arrange
	std::stringstream stream;

	//Act

	//Assert
	ASSERT_ANY_THROW(Message(stream, "Hello, % % world! %"));
}

TEST(Message_test, Exception_with_lack_of_arguments_Single_argument_case_test)
{
	//Arrange
	std::stringstream stream;

	//Act

	//Assert
	ASSERT_ANY_THROW(Message(stream, "Hello, % % world! %", "my"));
}

TEST(Message_test, Exception_with_lack_of_arguments_Several_arguments_case_test)
{
	//Arrange
	std::stringstream stream;

	//Act

	//Assert
	ASSERT_ANY_THROW(Message(stream, "Hello, % % world! %", "my", "bright"));
}

