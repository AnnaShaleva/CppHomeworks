#include <iostream>
#include "MyGuard.hh"
#include <gtest/gtest.h>

struct Guard_param
{
	char FillCh;
	int Width;
};

class MyGuard_test: public ::testing::TestWithParam<Guard_param> {};

TEST_P(MyGuard_test, MyGuard_correct_work_test)
{
	//Arrange
	const Guard_param& params = GetParam();
	std::cout.fill(params.FillCh);
	std::cout.width(params.Width);
	MyGuard* pt = new MyGuard(std::cout);
	
	//Act
	std::cout.fill('+');
	std::cout.width(5);
	delete pt;
	
	//Assert
	EXPECT_EQ(params.FillCh, std::cout.fill());
	EXPECT_EQ(params.Width, std::cout.width());
}

INSTANTIATE_TEST_CASE_P(
		_,
		MyGuard_test,
		::testing::Values(
			Guard_param{
			'-',
			5
			},
			Guard_param{
			' ',
			10
			}
			)
		);
