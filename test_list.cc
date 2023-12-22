#include <gtest/gtest.h>

#include "s21_list.h"
#include <list>

template <typename T>
void checkEquals(const std::list<T> &stdlst, s21::list<T> &s21lst)
{
    ASSERT_EQ(stdlst.size(), s21lst.size());
    auto itStd = stdlst.begin();
    auto itS21 = s21lst.begin();
    while (itS21 != s21lst.end())
    {
        ASSERT_EQ(*itStd, *itS21);
        ++itStd;
        ++itS21;
    }
}

TEST(List, Insert)
{
    s21::list<int> s21lst;
    std::list<int> stdlst;
    for (int i = 0; i < 10; ++i)
    {
        s21lst.insert(s21lst.begin(), i);
        stdlst.insert(stdlst.begin(), i);
    }
    checkEquals(stdlst, s21lst);
}

TEST(List, Erase)
{
    s21::list<int> s21lst{1, 2, 3, 4};
    std::list<int> stdlst{1, 2, 3, 4};
    s21lst.erase(++(s21lst.begin()));
    stdlst.erase(++(stdlst.begin()));
    checkEquals(stdlst, s21lst);

    s21::list<int> s21lst2{1};
    std::list<int> stdlst2{1};
    s21lst2.erase(s21lst2.begin());
    stdlst2.erase(stdlst2.begin());
    ASSERT_EQ(stdlst2.size(), s21lst2.size());
}

TEST(List, PopFront)
{
    s21::list<int> s21lst{1, 2, 3, 4};
    std::list<int> stdlst{1, 2, 3, 4};
    s21lst.pop_front();
    stdlst.pop_front();
    checkEquals(stdlst, s21lst);
}

TEST(List, PopBack)
{
    s21::list<int> s21lst{1, 2, 3, 4};
    std::list<int> stdlst{1, 2, 3, 4};
    s21lst.pop_back();
    stdlst.pop_back();
    checkEquals(stdlst, s21lst);
}

TEST(List, PushFront)
{
    s21::list<int> s21lst;
    std::list<int> stdlst;
    for (int i = 0; i < 10; ++i)
    {
        s21lst.push_front(i);
        stdlst.push_front(i);
    }
    checkEquals(stdlst, s21lst);
}

TEST(List, PushBack)
{
    s21::list<int> s21lst;
    std::list<int> stdlst;
    for (int i = 0; i < 10; ++i)
    {
        s21lst.push_back(i);
        stdlst.push_back(i);
    }
    checkEquals(stdlst, s21lst);
}

TEST(List, Constructors)
{
    s21::list<int> s21lst(3);
    std::list<int> stdlst(3);
    checkEquals(stdlst, s21lst);

    s21::list<int> s21lst2{1, 2, 3, 4};
    std::list<int> stdlst2{1, 2, 3, 4};
    checkEquals(stdlst2, s21lst2);

    s21::list<int> s21lst3(s21lst2);
    std::list<int> stdlst3(stdlst2);
    checkEquals(stdlst3, s21lst3);

    s21::list<int> s21lst4(std::move(s21lst3));
    std::list<int> stdlst4(std::move(stdlst3));
    checkEquals(stdlst4, s21lst4);
}

TEST(List, OperatorEq)
{
    s21::list<int> s21lst{1, 2, 3, 4};
    std::list<int> stdlst{1, 2, 3, 4};
    s21::list<int> s21lst2;
    std::list<int> stdlst2;
    s21lst2 = s21lst;
    stdlst2 = stdlst;
    checkEquals(stdlst2, s21lst2);

    s21lst = std::move(s21lst2);
    stdlst = std::move(stdlst2);
    checkEquals(stdlst, s21lst);
}

TEST(ListPushBack, True)
{
    s21::list<int> school1;
    std::list<int> std1;
    for (int i = 1; i < 10; ++i)
    {
        school1.push_back(i * i);
        std1.push_back(i * i);
    }
    auto stdIterator = std1.begin();
    auto s21Iterator = school1.begin();
    while (s21Iterator != school1.end())
    {
        ASSERT_EQ(*stdIterator, *s21Iterator);
        ++stdIterator;
        ++s21Iterator;
    }
}

TEST(ListInsert, True)
{
    s21::list<int> school1{1, 2, 3, 4, 5};
    std::list<int> std1{1, 2, 3, 4, 5};

    auto stdIterator = std1.begin();
    auto s21Iterator = school1.begin();
    school1.insert(s21Iterator, 100);
    std1.insert(stdIterator, 100);
    while (s21Iterator != school1.end())
    {
        ASSERT_EQ(*stdIterator, *s21Iterator);
        ++stdIterator;
        ++s21Iterator;
    }

    s21::list<int> school2{1, 2, 3, 4, 5};
    std::list<int> std2{1, 2, 3, 4, 5};
    auto stdIterator2 = std2.begin();
    auto s21Iterator2 = school2.begin();
    for (size_t i = 0; i < 3; ++i)
    {
        ++stdIterator2;
        ++s21Iterator2;
    }
    school2.insert(s21Iterator2, 1111);
    std2.insert(stdIterator2, 1111);
    auto tempS21Iterator = school2.begin();
    auto tempStdIterator = std2.begin();
    while (tempS21Iterator != school2.end())
    {
        ASSERT_EQ(*tempS21Iterator, *tempStdIterator);
        ++tempS21Iterator;
        ++tempStdIterator;
    }

    s21::list<int> school3;
    std::list<int> std3;
    school3.insert(school3.begin(), 100);
    std3.insert(std3.begin(), 100);
    ASSERT_EQ(*school3.begin(), *std3.begin());
}

TEST(ListErase, True)
{
    s21::list<int> school1{1, 2, 3, 4, 5};
    std::list<int> std1{1, 2, 3, 4, 5};

    school1.erase(school1.begin());
    std1.erase(std1.begin());
    auto stdIterator = std1.begin();
    auto s21Iterator = school1.begin();
    while (s21Iterator != school1.end())
    {
        ASSERT_EQ(*stdIterator, *s21Iterator);
        ++stdIterator;
        ++s21Iterator;
    }

    s21::list<int> school2{1, 2, 3, 4, 5};
    std::list<int> std2{1, 2, 3, 4, 5};
    auto stdIterator2 = std2.begin();
    auto s21Iterator2 = school2.begin();
    for (size_t i = 0; i < 3; ++i)
    {
        ++stdIterator2;
        ++s21Iterator2;
    }
    school2.erase(s21Iterator2);
    std2.erase(stdIterator2);
    auto tempS21Iterator = school2.begin();
    auto tempStdIterator = std2.begin();
    while (tempS21Iterator != school2.end())
    {
        ASSERT_EQ(*tempS21Iterator, *tempStdIterator);
        ++tempS21Iterator;
        ++tempStdIterator;
    }

    s21::list<int> school3{1};
    std::list<int> std3{1};
    school3.erase(school3.begin());
    std3.erase(std3.begin());
    ASSERT_EQ(school3.size(), std3.size());
}

TEST(ListPopBack, True)
{
    s21::list<int> school1{1, 2, 3, 4, 5};
    std::list<int> std1{1, 2, 3, 4, 5};

    school1.pop_back();
    std1.pop_back();
    auto stdIterator = std1.begin();
    auto s21Iterator = school1.begin();
    while (s21Iterator != school1.end())
    {
        ASSERT_EQ(*stdIterator, *s21Iterator);
        ++stdIterator;
        ++s21Iterator;
    }

    s21::list<int> school2{1, 2, 3, 4, 5};
    std::list<int> std2{1, 2, 3, 4, 5};
    for (size_t i = 0; i < 3; ++i)
    {
        school2.pop_back();
        std2.pop_back();
    }
    auto tempS21Iterator = school2.begin();
    auto tempStdIterator = std2.begin();
    while (tempS21Iterator != school2.end())
    {
        ASSERT_EQ(*tempS21Iterator, *tempStdIterator);
        ++tempS21Iterator;
        ++tempStdIterator;
    }
}

TEST(ListPopFront, True)
{
    s21::list<int> school1{1, 2, 3, 4, 5};
    std::list<int> std1{1, 2, 3, 4, 5};

    school1.pop_front();
    std1.pop_front();
    auto stdIterator = std1.begin();
    auto s21Iterator = school1.begin();
    while (s21Iterator != school1.end())
    {
        ASSERT_EQ(*stdIterator, *s21Iterator);
        ++stdIterator;
        ++s21Iterator;
    }

    s21::list<int> school2{1, 2, 3, 4, 5};
    std::list<int> std2{1, 2, 3, 4, 5};
    for (size_t i = 0; i < 3; ++i)
    {
        school2.pop_front();
        std2.pop_front();
    }
    auto tempS21Iterator = school2.begin();
    auto tempStdIterator = std2.begin();
    while (tempS21Iterator != school2.end())
    {
        ASSERT_EQ(*tempS21Iterator, *tempStdIterator);
        ++tempS21Iterator;
        ++tempStdIterator;
    }
}

TEST(ListPushFront, True)
{
    s21::list<int> school1;
    std::list<int> std1;
    for (int i = 1; i < 10; ++i)
    {
        school1.push_front(i * i);
        std1.push_front(i * i);
    }
    auto stdIterator = std1.begin();
    auto s21Iterator = school1.begin();
    while (s21Iterator != school1.end())
    {
        ASSERT_EQ(*stdIterator, *s21Iterator);
        ++stdIterator;
        ++s21Iterator;
    }
}

TEST(List, Clear)
{
    s21::list<int> s21lst{1, 2, 3, 4};
    std::list<int> stdlst{1, 2, 3, 4};
    s21lst.clear();
    stdlst.clear();
}

TEST(List, Size)
{
    s21::list<int> s21lst{1, 2, 3, 4};
    std::list<int> stdlst{1, 2, 3, 4};
    ASSERT_EQ(stdlst.size(), s21lst.size());
    s21lst.clear();
    stdlst.clear();
    ASSERT_EQ(stdlst.size(), s21lst.size());
    ASSERT_EQ(stdlst.empty(), s21lst.empty());

    s21::list<int> my_list;
    size_t max_size = my_list.max_size();
    ASSERT_EQ(max_size, std::numeric_limits<size_t>::max() / sizeof(int));
}

TEST(List, Front)
{
    s21::list<int> s21lst{1, 2, 3, 4};
    std::list<int> stdlst{1, 2, 3, 4};
    ASSERT_EQ(stdlst.front(), s21lst.front());
}

TEST(List, Back)
{
    s21::list<int> s21lst{1, 2, 3, 4};
    std::list<int> stdlst{1, 2, 3, 4};
    ASSERT_EQ(stdlst.back(), s21lst.back());
}

TEST(List, Reverse)
{
    s21::list<int> s21lst{1, 2, 3, 4};
    std::list<int> stdlst{1, 2, 3, 4};
    s21lst.reverse();
    stdlst.reverse();
    checkEquals(stdlst, s21lst);
}

TEST(List, Sort)
{
    s21::list<int> s21lst{5, 4, 3, 2, 1, 34, 5, 5, 63, 56, 1, 0};
    std::list<int> stdlst{5, 4, 3, 2, 1, 34, 5, 5, 63, 56, 1, 0};
    s21lst.sort();
    stdlst.sort();
    checkEquals(stdlst, s21lst);
}

// TEST(List, Merge1)
// {
//     s21::list<int> s21lst1{5,9,0,1,3}; //0 1 3 5 9
//     std::list<int> stdlst1{5,9,0,1,3};
//     s21::list<int> s21lst2{8,7,2,6,4}; //2 4 6 7 8
//     std::list<int> stdlst2{8,7,2,6,4};
//     s21lst1.merge(s21lst2);
//     stdlst1.merge(stdlst2);
//     checkEquals(stdlst1, s21lst1); //0 1 2 3 4 5 6 7 8 9
//     // checkEquals(stdlst2, s21lst2);
// }

// TEST(List, Merge2)
// {
//     s21::list<int> s21lst1{1, 2, 3, 4}; 
//     std::list<int> stdlst1{1, 2, 3, 4};
//     s21::list<int> s21lst2{1, 2, 3, 4}; 
//     std::list<int> stdlst2{1, 2, 3, 4};
//     s21lst1.merge(s21lst2);
//     stdlst1.merge(stdlst2);
//     checkEquals(stdlst1, s21lst1);
//     // checkEquals(stdlst2, s21lst2);
// }

TEST(List, Merge1)
{
    s21::list<int> s21lst1{0, 1, 3, 5, 9}; 
    std::list<int> stdlst1{0, 1, 3, 5, 9};
    s21::list<int> s21lst2{2, 4, 6, 7, 8}; 
    std::list<int> stdlst2{2, 4, 6, 7, 8};
    s21lst1.merge(s21lst2);
    stdlst1.merge(stdlst2);
    checkEquals(stdlst1, s21lst1); //0 1 2 3 4 5 6 7 8 9
    // checkEquals(stdlst2, s21lst2);
}

TEST(List, Unique)
{
    s21::list<int> s21lst1{1, 2, 2, 3, 3, 2, 1, 1, 2}; 
    std::list<int> stdlst1{1, 2, 2, 3, 3, 2, 1, 1, 2};
    s21lst1.unique();
    stdlst1.unique();
    checkEquals(stdlst1, s21lst1);
}

TEST(List, Splice)
{
    s21::list<int> s21lst1{1, 2, 3, 4, 5};
    s21::list<int> s21lst2 {10, 20, 30, 40, 50};
    std::list<int> stdlst1 {1, 2, 3, 4, 5};
    std::list<int> stdlst2 {10, 20, 30, 40, 50};
    s21lst1.splice(s21lst1.cbegin(), s21lst2);
    stdlst1.splice(stdlst1.cbegin(), stdlst2);
    checkEquals(stdlst1, s21lst1);
    ASSERT_TRUE(s21lst2.empty());
}