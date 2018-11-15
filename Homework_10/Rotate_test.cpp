#include <vector>
#include <iostream>
#include "Rotate.hh"
#include <gtest/gtest.h>

TEST(Rotate_test, Rotate_first_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = 4;
	expectedResult[1] = -1;

	//Act
	Rotate(result, 90);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_second_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = -1;
	expectedResult[1] = -4;

	//Act
	Rotate(result, 180);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_third_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = -4;
	expectedResult[1] = 1;

	//Act
	Rotate(result, 270);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_fourth_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = 1;
	expectedResult[1] = 4;

	//Act
	Rotate(result, 360);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_mnogo_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = 4;
	expectedResult[1] = -1;

	//Act
	Rotate(result, 450);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_minus_first_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = -4;
	expectedResult[1] = 1;

	//Act
	Rotate(result, -90);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_minus_second_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = -1;
	expectedResult[1] = -4;

	//Act
	Rotate(result, -180);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_minus_third_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = 4;
	expectedResult[1] = -1;

	//Act
	Rotate(result, -270);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_minus_fourth_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = 1;
	expectedResult[1] = 4;

	//Act
	Rotate(result, -360);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_minus_mnogo_quoter_test)
{	
	//Arrange
	auto result = std::vector<int>(2);
	result[0] = 1;
	result[1] = 4;
	auto expectedResult = std::vector<int>(2);
	expectedResult[0] = -4;
	expectedResult[1] = 1;

	//Act
	Rotate(result, -450);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(Rotate_test, Rotate_wrong_vector_test)
{	
	//Arrange
	auto v = std::vector<int>(3);
	v[0] = 1;
	v[1] = 4;
	v[2] = 3;
	auto expectedResult = -1;

	//Act
	auto result = Rotate(v, -450);
	
	//Assert
	EXPECT_EQ(expectedResult, result);
}
