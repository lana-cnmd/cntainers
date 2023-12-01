#include <gtest/gtest.h>

#include "s21_array.h"
#include <array>

TEST(Array, IL_Constructor)
{
    std::array<int, 3> stdArrInt{1, 2, 3};
    s21::array<int, 3> arrInt{1, 2, 3};
    ASSERT_EQ(stdArrInt.size(), arrInt.size());
    ASSERT_EQ(arrInt[0], 1);
    ASSERT_EQ(arrInt[1], 2);
    ASSERT_EQ(arrInt[2], 3);

    std::array<double, 3> stdArrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> arrDob{1.1, 2.2, 3.3};
    ASSERT_EQ(stdArrDob.size(), arrDob.size());
    ASSERT_DOUBLE_EQ(arrDob[0], 1.1);
    ASSERT_DOUBLE_EQ(arrDob[1], 2.2);
    ASSERT_DOUBLE_EQ(arrDob[2], 3.3);

    std::array<std::string, 3> stdArrStr{"Hey", ",", "you"};
    s21::array<std::string, 3> arrStr{"Hey", ",", "you"};
    ASSERT_EQ(stdArrStr.size(), arrStr.size());
    EXPECT_EQ(arrStr[0], "Hey");
    EXPECT_EQ(arrStr[1], ",");
    EXPECT_EQ(arrStr[2], "you");
}
//
TEST(Array, Move_Constructor)
{
    s21::array<int, 3> arrInt{1, 2, 3};
    s21::array<int, 3> arrInt2 = std::move(arrInt);
    ASSERT_EQ(arrInt2.size(), 3);
    ASSERT_EQ(arrInt2[0], 1);
    ASSERT_EQ(arrInt2[1], 2);
    ASSERT_EQ(arrInt2[2], 3);

    s21::array<double, 3> arrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> arrDob2 = std::move(arrDob);
    ASSERT_EQ(arrDob2.size(), 3);
    ASSERT_DOUBLE_EQ(arrDob2[0], 1.1);
    ASSERT_DOUBLE_EQ(arrDob2[1], 2.2);
    ASSERT_DOUBLE_EQ(arrDob2[2], 3.3);

    s21::array<std::string, 3> arrStr{"Hey", ",", "you"};
    s21::array<std::string, 3> arrStr2 = std::move(arrStr);
    ASSERT_EQ(arrStr2.size(), 3);
    EXPECT_EQ(arrStr2[0], "Hey");
    EXPECT_EQ(arrStr2[1], ",");
    EXPECT_EQ(arrStr2[2], "you");
}
//

TEST(Array, Move_Operator)
{
    s21::array<int, 3> arrInt{1, 2, 3};
    s21::array<int, 3> arrInt2;
    arrInt2 = std::move(arrInt);

    ASSERT_EQ(arrInt2.size(), 3);
    ASSERT_EQ(arrInt2[0], 1);
    ASSERT_EQ(arrInt2[1], 2);
    ASSERT_EQ(arrInt2[2], 3);

    s21::array<double, 3> arrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> arrDob2;
    arrDob2 = std::move(arrDob);
    ASSERT_EQ(arrInt2.size(), 3);
    ASSERT_EQ(arrInt2[0], 1);
    ASSERT_EQ(arrInt2[1], 2);
    ASSERT_EQ(arrInt2[2], 3);

    s21::array<std::string, 3> arrStr{"Hey", ",", "you"};
    s21::array<std::string, 3> arrStr2;
    arrStr2 = std::move(arrStr);
    ASSERT_EQ(arrStr2.size(), 3);
    EXPECT_EQ(arrStr2[0], "Hey");
    EXPECT_EQ(arrStr2[1], ",");
    EXPECT_EQ(arrStr2[2], "you");
}

TEST(Array, Copy_Constructor)
{
    s21::array<int, 3> arrInt{1, 2, 3};
    s21::array<int, 3> arrInt2(arrInt);
}