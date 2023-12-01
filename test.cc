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
    checkEquals(stdArrInt, s21arrInt);

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> s21arrDob2 = std::move(s21arrDob);
    std::array<double, 3> stdArrDob{1.1, 2.2, 3.3};
    std::array<double, 3> stdArrDob2 = std::move(stdArrDob);
    checkEquals(stdArrDob2, s21arrDob2);
    checkEquals(stdArrDob, s21arrDob);

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"}; // faLSE
    s21::array<std::string, 3> s21arrStr2 = std::move(s21arrStr);
    std::array<std::string, 3> stdArrStr{"Hey", ",", "you"};
    std::array<std::string, 3> stdArrStr2 = std::move(stdArrStr);
    checkEquals(stdArrStr2, s21arrStr2);
    checkEquals(stdArrStr, s21arrStr);
}

TEST(Array, Move_Operator) // segfault
{
    s21::array<int, 3> s21arrInt{1, 2, 3};
    s21::array<int, 3> s21arrInt2;
    s21arrInt2 = std::move(s21arrInt);
    std::array<int, 3> stdarrInt{1, 2, 3};
    std::array<int, 3> stdarrInt2;
    stdarrInt2 = std::move(stdarrInt);
    checkEquals(stdarrInt2, s21arrInt2);
    checkEquals(stdarrInt, s21arrInt);

    s21::array<double, 3> s21arrDob{1.1, 2.2, 3.3};
    s21::array<double, 3> s21arrDob2;
    s21arrDob2 = std::move(s21arrDob);
    std::array<double, 3> stdarrDob{1.1, 2.2, 3.3};
    std::array<double, 3> stdarrDob2;
    stdarrDob2 = std::move(stdarrDob);
    checkEquals(stdarrDob2, s21arrDob2);
    checkEquals(stdarrDob, s21arrDob);

    s21::array<std::string, 3> s21arrStr{"Hey", ",", "you"};
    s21::array<std::string, 3> s21arrStr2;
    s21arrStr2 = std::move(s21arrStr);
    std::array<std::string, 3> stdarrStr{"Hey", ",", "you"};
    std::array<std::string, 3> stdarrStr2;
    stdarrStr2 = std::move(stdarrStr);
    checkEquals(stdarrStr2, s21arrStr2);
    checkEquals(stdarrStr, s21arrStr);
}

// TEST(Array, Copy_Constructor)
// {
//     s21::array<int, 3> arrInt{1, 2, 3};
//     s21::array<int, 3> arrInt2(arrInt);
// }