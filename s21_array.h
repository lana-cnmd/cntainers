#ifndef CPP2_S21_CONTEINERS_1_S21_ARRAY_H
#define CPP2_S21_CONTEINERS_1_S21_ARRAY_H

#include <iostream>

namespace s21
{
    template <typename T, size_t N>
    struct array
    {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;

        // Implicitly-defined member functions:
        array() = default;

        array(std::initializer_list<value_type> const &items)
        {
            std::copy(items.begin(), items.end(), arr_);
        }

        array(const array &other)
        {
            for (size_type i = 0; i < other.size(); ++i)
            {
                std::copy(other.begin(), other.end(), arr_);
            }
        }

        array(array &&other) noexcept : array(other) {}

        array operator=(array &&other)
        {
            if (this != &other)
            {
                swap(other);
            }
            return *this;
        }

        array &operator=(const array &other) noexcept
        {
            for (size_type i = 0; i < N; ++i)
                arr_[i] = other.arr_[i];
            return *this;
        }

        ~array() = default;

        // Element access:
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
        const_reference front() const { return arr_[0]; }    // Calling front on an empty container causes undefined behavior.
        const_reference back() const { return arr_[N - 1]; } // Calling back on an empty container causes undefined behavior.
        iterator data() noexcept { return arr_; }

        // Iterators:
        iterator begin() noexcept { return arr_; }
        const_iterator begin() const noexcept { return arr_; }
        const_iterator cbegin() const noexcept { return arr_; }
        iterator end() noexcept { return arr_ + N; }
        const_iterator end() const noexcept { return arr_ + N; }
        const_iterator cend() const noexcept { return arr_ + N; }

        // Capacity:
        constexpr bool empty() const noexcept { return N == 0; }
        constexpr size_type size() const noexcept { return N; }
        constexpr size_type max_size() const noexcept { return N; }

        // Operations:
        void swap(array &other) noexcept // noexcept?
        {
            std::swap(arr_, other.arr_);
        }

        void fill(const_reference value)
        {
            for (size_type i = 0; i < N; ++i)
            {
                arr_[i] = value;
            }
        }

    public:
        T arr_[N];
    };

} // namespaсe s21
#endif // CPP2_S21_CONTEINERS_1_S21_ARRAY_H
