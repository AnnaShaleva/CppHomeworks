#include <myproject/MyVector.hh>
#include <gtest/gtest.h>

TEST(MyVecor_test, Create_Vector_test)
{
	//Arrange
	auto result = MyVector<int>(4, 3);
	auto expectedResult = MyVector<int>(4);
	for (int i = 0; i < 3; i++)
		expectedResult[i] = 3;

	//Act
	
	//Assert
	EXPECT_EQ(expectedResult[0], result[0]);
}
