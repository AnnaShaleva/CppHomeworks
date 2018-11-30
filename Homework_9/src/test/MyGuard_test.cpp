#include <iostream>
#include <myproject/MyGuard.hh>
#include <gtest/gtest.h>

struct Guard_param
{
	char FillCh;
	int Width;
	std::ios_base::fmtflags Flags;
};

class MyGuard_test: public ::testing::TestWithParam<Guard_param> {};

TEST_P(MyGuard_test, MyGuard_correct_work_test)
{
	//Arrange
	const Guard_param& params = GetParam();
	std::cout.fill(params.FillCh);
	std::cout.width(params.Width);
	std::cout.flags(params.Flags);
	MyGuard* pt = new MyGuard(std::cout);
	
	//Act
	std::cout.fill('+');
	std::cout.width(5);
	std::cout.flags(std::ios::right);
	delete pt;
	
	//Assert
	EXPECT_EQ(params.FillCh, std::cout.fill());
	EXPECT_EQ(params.Width, std::cout.width());
	EXPECT_EQ(params.Flags, std::cout.flags());
}

INSTANTIATE_TEST_CASE_P(
		_,
		MyGuard_test,
		::testing::Values(
			Guard_param{
			'-',
			7,
			std::ios::right
			},
			Guard_param{
			' ',
			10,
			std::ios::right
			}
			)
		);
