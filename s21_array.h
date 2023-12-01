#ifndef CPP2_S21_CONTEINERS_1_S21_ARRAY_H
#define CPP2_S21_CONTEINERS_1_S21_ARRAY_H

#include <iostream>

namespace s21
{
    template <typename T, size_t N>
    struct array
    {
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;

        array() = default;

        array(std::initializer_list<value_type> const &items)
        {
            size_t i = 0;
            for (auto it = items.begin(); it < items.end(); ++it)
            {
                arr_[i++] = *it;
            }
        }

        array(const array &other)
        {
            for (size_t i = 0; i < other.size(); ++i)
            {
                arr_[i] = other.arr_[i];
            }
        }

        array(array &&other) : array(other) {}

        array operator=(array &&other)
        {
            if (this != &other)
            {
                for (size_t i = 0; other.size(); ++i)
                {
                    arr_[i] = other.arr_[i];
                }
            }
            return *this;
        }

        ~array() = default;

        reference at(size_type pos)
        {
            if (pos > N - 1 || N == 0)
            {
                throw std::out_of_range("Out of range");
            }
            return arr_[pos];
        }

        reference operator[](size_type pos) { return arr_[pos]; }
        const_reference operator[](size_type pos) const { return arr_[pos]; }

        const_reference front() const { return arr_[0]; }

        const_reference back() const { return arr_[N - 1]; }

        iterator data() { return arr_; }

        iterator begin() { return arr_; }
        iterator begin() const { return arr_; }

        iterator end() { return arr_ + N; }
        iterator end() const { return arr_ + N; }

        bool empty() const { return N == 0; }

        size_type size() const noexcept { return N; }

        size_type max_size() const noexcept { return N; }

        void swap(array &other) noexcept
        {
            std::swap(*this, other);
        }

        void fill(const_reference value)
        {
            for (size_t i = 0; i < arr_.size(); ++i)
            {
                arr_[i] = value;
            }
        }

    public:
        T arr_[N];
    };
} // namespaсe s21
#endif // CPP2_S21_CONTEINERS_1_S21_ARRAY_H
