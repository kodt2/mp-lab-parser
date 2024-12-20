
#include <gtest.h>
#include "parser.h"

TEST(Parser, can)
{
	Parser parser;
	float res = parser.work("1");
	float res1 = 1;
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_unar_minus)
{
	Parser parser;
	float res = parser.work("-1");
	float res1 = -1;
	ASSERT_EQ(res, res1);
}
TEST(TSet, can_summ)
{
	Parser parser;
	float res = parser.work("12+454");
	float res1 = 12 + 454;
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_minus)
{
	Parser parser;
	float res = parser.work("45-9");
	float res1 = 45 - 9;
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_mul)
{
	Parser parser;
	float res = parser.work("78*23");
	float res1 = 78 * 23;
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_backets)
{
	Parser parser;
	float res = parser.work("2*(8-9)");
	float res1 = 2 * (8 - 9);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_close_backest)
{
	Parser parser;
	float res = parser.work("2*(8-9");
	float res1 = 2 * (8 - 9);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v1)
{
	Parser parser;
	float res = parser.work("(14.0+25.0*(-35.0*3.0+3.0/4.0)+4.0)/2.0");
	float res1 = (14.0 + 25.0 * (-35.0 * 3.0 + 3.0 / 4.0) + 4.0) / 2.0;
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v2)
{
	Parser parser;
	float res = parser.work("(23.0 + 45.0 * 12.0 - 18.0 / 3.0) + 56.0 * (32.0 - 7.0 / 2.0)");
	float res1 = (23.0 + 45.0 * 12.0 - 18.0 / 3.0) + 56.0 * (32.0 - 7.0 / 2.0);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v3)
{
	Parser parser;
	float res = parser.work("14.0 * (5.0 + 18.0 / 6.0 - 3.0) - 26.0 / (8.0 + 3.0)");
	float res1 = 14.0 * (5.0 + 18.0 / 6.0 - 3.0) - 26.0 / (8.0 + 3.0);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v4)
{
	Parser parser;
	float res = parser.work("(11.0 - 9.0 / 3.0 + 2.0 * 7.0) * (16.0 / 4.0 - 5.0 + 14.0)");
	float res1 = (11.0 - 9.0 / 3.0 + 2.0 * 7.0) * (16.0 / 4.0 - 5.0 + 14.0);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v5)
{
	Parser parser;
	float res = parser.work("25.0 - (8.0 * 3.0 + 14.0 / 2.0 - 5.0) * 2.0 + 18.0");
	float res1 = 25.0 - (8.0 * 3.0 + 14.0 / 2.0 - 5.0) * 2.0 + 18.0;
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v6)
{
	Parser parser;
	float res = parser.work("25.0 - (8.0 * 3.0 + 14.0 / 2.0 - 5.0) * 2.0 + 18.0");
	float res1 = 25.0 - (8.0 * 3.0 + 14.0 / 2.0 - 5.0) * 2.0 + 18.0;
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v7)
{
	Parser parser;
	float res = parser.work("(42.0 / 6.0 + 7.0 * 5.0 - 3.0) - 14.0 + 20.0 / (2.0 + 3.0)");
	float res1 = (42.0 / 6.0 + 7.0 * 5.0 - 3.0) - 14.0 + 20.0 / (2.0 + 3.0);
	EXPECT_EQ(res, res1);
}
TEST(Parser, can_diff_v8)
{
	Parser parser;
	float res = parser.work("32.0 + (14.0 - 8.0 * 4.0 / 2.0) * (19.0 + 25.0)");
	float res1 = 32.0 + (14.0 - 8.0 * 4.0 / 2.0) * (19.0 + 25.0);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v9)
{
	Parser parser;
	float res = parser.work("(21.0 * 3.0 + 6.0 / 2.0 - 15.0) / (8.0 + 5.0 * 2.0)");
	float res1 = (21.0 * 3.0 + 6.0 / 2.0 - 15.0) / (8.0 + 5.0 * 2.0);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v10)
{
	Parser parser;
	float res = parser.work("(21.0 * 3.0 + 6.0 / 2.0 - 15.0) / (8.0 + 5.0 * 2.0)");
	float res1 = (21.0 * 3.0 + 6.0 / 2.0 - 15.0) / (8.0 + 5.0 * 2.0);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v11)
{
	Parser parser;
	float res = parser.work("17.0 + (9.0 / 3.0 - 5.0 * 2.0 + 18.0) * 6.0 / 2.0");
	float res1 = 17.0 + (9.0 / 3.0 - 5.0 * 2.0 + 18.0) * 6.0 / 2.0;
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v12)
{
	Parser parser;
	float res = parser.work("(16.0 * 4.0 - 10.0 + 3.0 / 2.0) / (7.0 + 2.0 * 5.0)");
	float res1 = (16.0 * 4.0 - 10.0 + 3.0 / 2.0) / (7.0 + 2.0 * 5.0);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_diff_v13)
{
	Parser parser;
	float res = parser.work("(13.0 + 8.0 * 2.0 / 4.0 - 6.0) * (9.0 - 15.0 + 21.0)");
	float res1 = (13.0 + 8.0 * 2.0 / 4.0 - 6.0) * (9.0 - 15.0 + 21.0);
	ASSERT_EQ(res, res1);
}
TEST(Parser, can_final_boss)
{
	Parser parser;
	float res = parser.work("((23.5 * 4.8 + 5.9 - (13.5 / 2.1 - 9.6) * (4.5 + 18.3) / 3.2) - \
(2.4 * 9.7 + (16.3 - 7.5 / 3.1) * 8.2 / 2.6) + ((5.3 + 12.6 * 3.8) - (7.9 / 2.4 + 15.2) *\
 (3.5 - 8.4) / 4.7)) / ((18.2 - 9.5 + (6.3 * 2.9 - 4.1 / 2.0) * 3.6) + (8.4 * 1.3 + 5.7 / \
2.8 - (14.8 - 9.3) * 4.2 / 3.4) - ((12.1 + 4.5 * 2.2) / (9.6 - 3.1 + 5.4) * (8.3 / 4.6 - 1.8) \
* 3.2))");
	float res1 = ((23.5 * 4.8 + 5.9 - (13.5 / 2.1 - 9.6) * (4.5 + 18.3) / 3.2) - (2.4 * 9.7
		+ (16.3 - 7.5 / 3.1) * 8.2 / 2.6) + ((5.3 + 12.6 * 3.8) - (7.9 / 2.4 + 15.2) *
			(3.5 - 8.4) / 4.7)) / ((18.2 - 9.5 + (6.3 * 2.9 - 4.1 / 2.0) * 3.6) +
				(8.4 * 1.3 + 5.7 / 2.8 - (14.8 - 9.3) * 4.2 / 3.4) - ((12.1 + 4.5 * 2.2) /
					(9.6 - 3.1 + 5.4) * (8.3 / 4.6 - 1.8) * 3.2));
	ASSERT_NEAR(res, res1, 0.0000003f);
}
TEST(CalculatorParserTest, InvalidCharacter) {
	std::string expression = "3 + 5a - 2";
	Parser parser;
	EXPECT_ANY_THROW(parser.work("expression"));
}

TEST(CalculatorParserTest, UnbalancedParentheses) {
	std::string expression = "(3 + 5 * (2 - 7)";
	Parser parser;
	EXPECT_ANY_THROW(parser.work("expression"));
}

TEST(CalculatorParserTest, TwoOperatorsInARow) {
	std::string expression = "5 + * 3";
	Parser parser;
	EXPECT_ANY_THROW(parser.work("expression"));
}

TEST(CalculatorParserTest, StartsWithOperator) {
	std::string expression = "* 7 + 3";
	Parser parser;
	EXPECT_ANY_THROW(parser.work("expression"));
}

TEST(CalculatorParserTest, DoubleNegativeSigns) {
	std::string expression = "5 + --3";
	Parser parser;
	EXPECT_ANY_THROW(parser.work("expression"));
}

TEST(CalculatorParserTest, MultipleDecimalPoints) {
	std::string expression = "2.3.4 + 5";
	Parser parser;
	EXPECT_ANY_THROW(parser.work("expression"));
}

TEST(CalculatorParserTest, EndsWithOperator) {
	std::string expression = "8 + 7 * ";
	Parser parser;
	EXPECT_ANY_THROW(parser.work("expression"));
}

TEST(CalculatorParserTest, EmptyString) {
	std::string expression = "";
	Parser parser;
	EXPECT_ANY_THROW(parser.work("expression"));
}