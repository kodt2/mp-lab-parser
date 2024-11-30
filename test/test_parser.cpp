#include <gtest.h>
#include "parser.h"

TEST(Parser, can)
{
	Parser parser;
	float res = parser.work("1");
	float res1 = 1;
	EXPECT_EQ(res,res1);
}
TEST(Parser, can_unar_minus)
{
	Parser parser;
	float res = parser.work("-1");
	float res1 = -1;
	EXPECT_EQ(res, res1);
}
TEST(TSet, can_summ)
{
	Parser parser;
	float res = parser.work("12+454");
	float res1 = 12+454;
	EXPECT_EQ(res, res1);
}
TEST(Parser, can_minus)
{
	Parser parser;
	float res = parser.work("45-9");
	float res1 = 45-9;
	EXPECT_EQ(res, res1);
}
TEST(Parser, can_mul)
{
	Parser parser;
	float res = parser.work("78*23");
	float res1 = 78*23;
	EXPECT_EQ(res, res1);
}
TEST(Parser, can_div)
{
	Parser parser;
	float res1 = 5.0/19.0;
	EXPECT_EQ(parser.work("5/19"), res1);
}
TEST(Parser, can_backets)
{
	Parser parser;
	float res = parser.work("2*(8-9)");
	float res1 = 2 * (8 - 9);
	EXPECT_EQ(res, res1);
}
TEST(Parser, can_close_backest)
{
	Parser parser;
	float res = parser.work("2*(8-9");
	float res1 = 2 * (8 - 9);
	EXPECT_EQ(res, res1);
}
TEST(Parser, can_diff_v1)
{
	Parser parser;
	float res = parser.work("(14.0+25.0*(-35.0*3.0+3.0/4.0)+4.0)/2.0");
	float res1 = (14.0 + 25.0 * (-35.0 * 3.0 + 3.0 / 4.0) + 4.0) / 2.0;
	EXPECT_EQ(res, res1);
}