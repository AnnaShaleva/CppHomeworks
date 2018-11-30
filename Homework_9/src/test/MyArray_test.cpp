#include <myproject/MyArray.hh>
#include <gtest/gtest.h>

TEST(MyArray_test, MyArray_Brackets_test)
{
	//Arrange
	auto a = MyArray<int>(2,2);
	int expectedResult = 1;
	a(0,0) = expectedResult;

	//Act
	auto result = a(0,0);

	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST(MyArray_test, MyArray_Mask_test)
{
	//Arrange
	auto a = MyArray<int>(2,2);
	auto mask = MyArray<bool>(2,2);
	auto expectedResult = MyArray<int>(2,2);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			a(i, j) = 1;
			mask(i, j) = 0;
			expectedResult(i, j) = 1;
		}
	int value = 5;
	mask(0, 0) = 1;
	expectedResult(0, 0) = value; 

	//Act
	a(mask) = value;

	//Assert
	EXPECT_EQ(expectedResult, a);
}

