#include "MyArray.hh"
#include <gtest/gtest.h>

struct MyArray_param
{
	MyArray<int> firstArray;
	MyArray<int> secondArray;
	MyArray<int> result;
};

class MyArray_test: public ::testing::TestWithParam<MyArray_param> {};

TEST_P(MyArray_test, MyArray_sum_test)
{
	//Arrange
	const MyArray_param& params = GetParam();
	auto a1 = params.firstArray;
	auto a2 = params.secondArray;
	auto expectedResult = params.result;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			a1(i, j) = i + j;
			a2(i, j) = i + j;
			expectedResult(i, j) = 2 * (i + j);
		}

	//Act
	auto result = a1 + a2;

	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST_P(MyArray_test, MyArray_diff_test)
{
	//Arrange
	const MyArray_param& params = GetParam();
	auto a1 = params.firstArray;
	auto a2 = params.secondArray;
	auto expectedResult = params.result;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			a1(i, j) = 3 * (i + j);
			a2(i, j) = i + j;
			expectedResult(i, j) = 2 * (i + j);
		}

	//Act
	auto result = a1 - a2;

	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST_P(MyArray_test, MyArray_umnojit_test)
{
	//Arrange
	const MyArray_param& params = GetParam();
	auto a1 = params.firstArray;
	auto a2 = params.secondArray;
	auto expectedResult = params.result;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			a1(i, j) = i + j + 2;
			a2(i, j) = i + j + 5;
			expectedResult(i, j) = (i + j + 2) * (i + j + 5);
		}

	//Act
	auto result = a1 * a2;

	//Assert
	EXPECT_EQ(expectedResult, result);
}


TEST_P(MyArray_test, MyArray_dev_test)
{
	//Arrange
	const MyArray_param& params = GetParam();
	auto a1 = params.firstArray;
	auto a2 = params.secondArray;
	auto expectedResult = params.result;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			a1(i, j) = 6 * (i + j + 2);
			a2(i, j) = 2 * (i + j + 2);
			expectedResult(i, j) = 3;
		}

	//Act
	auto result = a1 / a2;

	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST_P(MyArray_test, MyArray_And_test)
{
	//Arrange
	const MyArray_param& params = GetParam();
	auto a1 = params.firstArray;
	auto a2 = params.secondArray;
	auto expectedResult = MyArray<bool>(2,2);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			a1(i, j) = 6 * (i + j + 2);
			a2(i, j) = 2 * (i + j + 2);
			expectedResult(i, j) = a1(i,j) && a2(i,j);
		}

	//Act
	auto result = a1 && a2;

	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST_P(MyArray_test, MyArray_Or_test)
{
	//Arrange
	const MyArray_param& params = GetParam();
	auto a1 = params.firstArray;
	auto a2 = params.secondArray;
	auto expectedResult = MyArray<bool>(2,2);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			a1(i, j) = 6 * (i + j + 2);
			a2(i, j) = 2 * (i + j + 2);
			expectedResult(i, j) = a1(i,j) || a2(i,j);
		}

	//Act
	auto result = a1 || a2;

	//Assert
	EXPECT_EQ(expectedResult, result);
}

TEST_P(MyArray_test, MyArray_Not_test)
{
	//Arrange
	const MyArray_param& params = GetParam();
	auto a1 = params.firstArray;
	auto expectedResult = MyArray<bool>(2,2);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			a1(i, j) = 6 * (i + j + 2);
			expectedResult(i, j) = !a1(i,j);
		}

	//Act
	auto result = !a1;

	//Assert
	EXPECT_EQ(expectedResult, result);
}




INSTANTIATE_TEST_CASE_P(
		_,
		MyArray_test,
		::testing::Values(
			MyArray_param{
			MyArray<int>(2, 2),
			MyArray<int> (2, 2),
			MyArray<int>(2, 2)
			}
			)
		);
