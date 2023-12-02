#include <gtest/gtest.h>

#include "s21_array.h"
#include <array>

template <typename T, size_t N>
void checkEquals(const std::array<T, N> &stdarr, const s21::array<T, N> &s21arr)
{
    ASSERT_EQ(stdarr.size(), s21arr.size());
    for (size_t i = 0; i < s21arr.size(); ++i)
    {
        ASSERT_EQ(stdarr[i], s21arr[i]);
    }
}

TEST(Array, IL_Constructor)
{
    std::array<int, 3> stdArrInt{1, 2, 3};
    s21::array<int, 3> s21arrInt{1, 2, 3};
    checkEquals(stdArrInt, s21arrInt);

    std::array<double, 3> stdArrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    checkEquals(stdArrDob, s21arrDob);

    std::array<std::string, 3> stdArrStr{"Hey", ",", "you"};
    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    checkEquals(stdArrStr, s21arrStr);
}

TEST(Array, Move_Constructor)
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    s21::array<int, 3> s21arrInt2 = std::move(s21arrInt);
    std::array<int, 3> stdArrInt{1, 2, 3};
    std::array<int, 3> stdArrInt2 = std::move(stdArrInt);
    checkEquals(stdArrInt2, s21arrInt2);

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> s21arrDob2 = std::move(s21arrDob);
    std::array<double, 3> stdArrDob{1.1, 2.2, 3.3};
    std::array<double, 3> stdArrDob2 = std::move(stdArrDob);
    checkEquals(stdArrDob2, s21arrDob2);

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"}; // faLSE
    s21::array<std::string, 3> s21arrStr2 = std::move(s21arrStr);
    std::array<std::string, 3> stdArrStr{"Hey", ",", "you"};
    std::array<std::string, 3> stdArrStr2 = std::move(stdArrStr);
    checkEquals(stdArrStr2, s21arrStr2);
}

TEST(Array, Move_Operator)
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    s21::array<int, 3> s21arrInt2;
    s21arrInt2 = std::move(s21arrInt);
    std::array<int, 3> stdarrInt{1, 2, 3};
    std::array<int, 3> stdarrInt2;
    stdarrInt2 = std::move(stdarrInt);
    checkEquals(stdarrInt2, s21arrInt2);

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> s21arrDob2;
    s21arrDob2 = std::move(s21arrDob);
    std::array<double, 3> stdarrDob{1.1, 2.2, 3.3};
    std::array<double, 3> stdarrDob2;
    stdarrDob2 = std::move(stdarrDob);
    checkEquals(stdarrDob2, s21arrDob2);

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    s21::array<std::string, 3> s21arrStr2;
    s21arrStr2 = std::move(s21arrStr);
    std::array<std::string, 3> stdarrStr{"Hey", ",", "you"};
    std::array<std::string, 3> stdarrStr2;
    stdarrStr2 = std::move(stdarrStr);
    checkEquals(stdarrStr2, s21arrStr2);
}

TEST(Array, Copy_Constructor)
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    s21::array<int, 3> s21arrInt2(s21arrInt);
    std::array<int, 3> stdarrInt{1, 2, 3};
    std::array<int, 3> stdarrInt2(stdarrInt);
    checkEquals(stdarrInt2, s21arrInt2);
    checkEquals(stdarrInt, s21arrInt);

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> s21arrDob2(s21arrDob);
    std::array<double, 3> stdarrDob{1.1, 2.2, 3.3};
    std::array<double, 3> stdarrDob2(stdarrDob);
    checkEquals(stdarrDob2, s21arrDob2);
    checkEquals(stdarrDob, s21arrDob);

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    s21::array<std::string, 3> s21arrStr2(s21arrStr);
    std::array<std::string, 3> stdarrStr{"Hey", ",", "you"};
    std::array<std::string, 3> stdarrStr2(stdarrStr);
    checkEquals(stdarrStr2, s21arrStr2);
    checkEquals(stdarrStr, s21arrStr);
}

TEST(Array, At)
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    std::array<int, 3> stdarrInt{1, 2, 3};
    ASSERT_EQ(stdarrInt.at(0), s21arrInt.at(0));
    ASSERT_EQ(stdarrInt.at(1), s21arrInt.at(1));
    ASSERT_EQ(stdarrInt.at(2), s21arrInt.at(2));
    ASSERT_ANY_THROW(s21arrInt.at(4));

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    std::array<double, 3> stdarrDob{1.1, 2.2, 3.3};
    ASSERT_DOUBLE_EQ(stdarrDob.at(0), s21arrDob.at(0));
    ASSERT_DOUBLE_EQ(stdarrDob.at(1), s21arrDob.at(1));
    ASSERT_DOUBLE_EQ(stdarrDob.at(2), s21arrDob.at(2));
    ASSERT_ANY_THROW(s21arrDob.at(5));

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    std::array<std::string, 3> stdarrStr{"Hey", ",", "you"};
    ASSERT_EQ(stdarrStr.at(0), s21arrStr.at(0));
    ASSERT_EQ(stdarrStr.at(1), s21arrStr.at(1));
    ASSERT_EQ(stdarrStr.at(2), s21arrStr.at(2));
    ASSERT_ANY_THROW(s21arrStr.at(4));
}

TEST(Array, FrontBackSize)
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    std::array<int, 3> stdarrInt{1, 2, 3};
    ASSERT_EQ(stdarrInt.front(), s21arrInt.front());
    ASSERT_EQ(stdarrInt.back(), s21arrInt.back());
    ASSERT_EQ(stdarrInt.size(), s21arrInt.size());
    ASSERT_EQ(stdarrInt.max_size(), s21arrInt.max_size());

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    std::array<double, 3> stdarrDob{1.1, 2.2, 3.3};
    ASSERT_DOUBLE_EQ(stdarrDob.front(), s21arrDob.front());
    ASSERT_DOUBLE_EQ(stdarrDob.back(), s21arrDob.back());
    ASSERT_EQ(stdarrDob.size(), s21arrDob.size());
    ASSERT_EQ(stdarrDob.max_size(), s21arrDob.max_size());

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    std::array<std::string, 3> stdarrStr{"Hey", ",", "you"};
    ASSERT_EQ(stdarrStr.front(), s21arrStr.front());
    ASSERT_EQ(stdarrStr.back(), s21arrStr.back());
    ASSERT_EQ(stdarrStr.size(), s21arrStr.size());
    ASSERT_EQ(stdarrStr.max_size(), s21arrStr.max_size());
}

TEST(Array, Data) {
  s21::array<int, 3> s21arrInt{1, 2, 3};
  ASSERT_EQ(*s21arrInt.data(), 1);

  s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
  ASSERT_DOUBLE_EQ(*s21arrDob.data(), 1.1);

  s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
  ASSERT_EQ(*s21arrStr.data(), "Hey");
}

TEST(Array, Swap)
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    s21::array<int, 3> s21arrInt2{4, 5, 6};
    std::array<int, 3> stdarrInt{1, 2, 3};
    std::array<int, 3> stdarrInt2{4, 5, 6};
    s21arrInt.swap(s21arrInt2);
    stdarrInt.swap(stdarrInt2);
    checkEquals(stdarrInt, s21arrInt);
    checkEquals(stdarrInt2, s21arrInt2);

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> s21arrDob2{6.1, 7.2, 8.3};
    std::array<double, 3> stdarrDob{1.1, 2.2, 3.3};
    std::array<double, 3> stdarrDob2{6.1, 7.2, 8.3};
    s21arrDob.swap(s21arrDob2);
    stdarrDob.swap(stdarrDob2);
    checkEquals(stdarrDob, s21arrDob);
    checkEquals(stdarrDob2, s21arrDob2);

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    s21::array<std::string, 3> s21arrStr2{"^", "*", "^"};
    std::array<std::string, 3> stdarrStr{"Hey", ",", "you"};
    std::array<std::string, 3> stdarrStr2{"^", "*", "^"};
    s21arrStr.swap(s21arrStr2);
    stdarrStr.swap(stdarrStr2);
    checkEquals(stdarrStr, s21arrStr);
    checkEquals(stdarrStr2, s21arrStr2);
}

TEST(Array, Empty)
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    s21::array<int, 0> s21arrInt2;
    ASSERT_EQ(s21arrInt.empty(), false);
    ASSERT_EQ(s21arrInt2.empty(), true);

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    s21::array<double, 0> s21arrDob2;
    ASSERT_EQ(s21arrDob.empty(), false);
    ASSERT_EQ(s21arrDob2.empty(), true);

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    s21::array<std::string, 0> s21arrStr2;
    ASSERT_EQ(s21arrStr.empty(), false);
    ASSERT_EQ(s21arrStr2.empty(), true);
}

TEST(Array, Fill)
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    s21arrInt.fill(33);
    std::array<int, 3> stdarrInt{1, 2, 3};
    stdarrInt.fill(33);
    checkEquals(stdarrInt, s21arrInt);

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    s21arrDob.fill(0.0);
    std::array<double, 3> stdarrDob{1.1, 2.2, 3.3};
    stdarrDob.fill(0.0);
    checkEquals(stdarrDob, s21arrDob);

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    s21arrStr.fill("^_^");
    std::array<std::string, 3> stdarrStr{"Hey", ",", "you"};
    stdarrStr.fill("^_^");
    checkEquals(stdarrStr, s21arrStr);
}

TEST(Array, BracketsOperator)
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    ASSERT_EQ(s21arrInt[0], 1);

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    ASSERT_DOUBLE_EQ(s21arrDob[0], 1.1);

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    ASSERT_EQ(s21arrStr[0], "Hey");
}