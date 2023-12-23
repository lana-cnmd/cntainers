#ifndef CPP2_S21_CONTEINERS_1_S21_LIST_H
#define CPP2_S21_CONTEINERS_1_S21_LIST_H

#include <iostream>
#include <memory>
#include <algorithm>

namespace s21
{

    template <typename T>
    class list
    {
    public:
        class ListIterator;
        class ListConstIterator;

        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = ListIterator;
        using const_iterator = ListConstIterator;
        using size_type = size_t;

        // Member functions:
        list() : phantomNode(new Node), size_(0) {}
        list(size_type n) : phantomNode(new Node), size_(0)
        {
            for (size_t i = 0; i < n; ++i)
            {
                push_back(value_type());
            }
        }
        list(std::initializer_list<value_type> const &items) : phantomNode(new Node), size_(0)
        {
            for (auto item : items)
            {
                push_back(item);
            }
        }

        list(const list &other) : phantomNode(new Node), size_(0)
        {
            for (auto it : other)
            {
                push_back(it);
            }
        }

        list(list &&other) noexcept : phantomNode(nullptr), size_(0)
        {
            swap(other);
        }

        ~list()
        {
            clear();
            if (phantomNode != nullptr)
                delete phantomNode;
        }

        list &operator=(const list &other)
        {
            if (&other != this)
            {
                list copy(other);
                swap(copy);
            }
            return *this;
        }

        list operator=(list &&other) noexcept
        {
            if (&other != this)
            {
                swap(other);
                other.clear();
            }
            return *this;
        }
        // Element access:
        const_reference front() const // Calling front on an empty container causes undefined behavior.
        {
            if (!size_)
            {
                throw std::out_of_range("list is empty");
            }
            return phantomNode->next_->data_;
        }

        const_reference back() const // Calling back on an empty container causes undefined behavior.
        {
            if (!size_)
            {
                throw std::out_of_range("list is empty");
            }
            return phantomNode->prev_->data_;
        }
        // Iterators:
        iterator begin() noexcept
        {
            return iterator(phantomNode->next_);
        }
        iterator begin() const noexcept
        {
            return iterator(phantomNode->next_);
        }
        const_iterator cbegin() const noexcept
        {
            return const_iterator(phantomNode->next_);
        }

        iterator end() noexcept
        {
            return iterator(phantomNode);
        }
        iterator end() const noexcept
        {
            return iterator(phantomNode);
        }
        const_iterator cend() const noexcept
        {
            return const_iterator(phantomNode);
        }
        // Capacity:
        bool empty() const noexcept
        {
            return size_ == 0;
        }

        size_t size() const noexcept
        {
            return size_;
        }

        size_type max_size() const noexcept
        {
            return std::numeric_limits<size_type>::max() / sizeof(value_type);
        }
        // Modifiers:
        void clear() noexcept
        {
            if (phantomNode == nullptr)
            {
                return;
            }
            size_t copy = size_;
            for (size_t i = 0; i < copy; ++i)
            {
                pop_back();
            }
        }

        iterator insert(iterator pos, const_reference value)
        {
            Node *ptr = new Node(value);
            if (size_ == 0)
            {
                ptr->next_ = phantomNode;
                ptr->prev_ = phantomNode;
                phantomNode->next_ = ptr;
                phantomNode->prev_ = ptr;
            }
            else
            {
                Node *left = pos.ptr_->prev_;
                Node *right = pos.ptr_;
                ptr->prev_ = left;
                ptr->next_ = right;
                left->next_ = ptr;
                right->prev_ = ptr;
            }
            ++size_;
            return iterator(ptr);
        }

        const_iterator insert(const_iterator pos, const_reference value)
        {
            Node *ptr = new Node(value);
            if (size_ == 0)
            {
                ptr->next_ = phantomNode;
                ptr->prev_ = phantomNode;
                phantomNode->next_ = ptr;
                phantomNode->prev_ = ptr;
            }
            else
            {
                Node *left = pos.ptr_->prev_;
                Node *right = pos.ptr_;
                ptr->prev_ = left;
                ptr->next_ = right;
                left->next_ = ptr;
                right->prev_ = ptr;
            }
            ++size_;
            return const_iterator(ptr);
        }

        void erase(iterator pos)
        {
            if (size_ == 1)
            {
                phantomNode->next_ = nullptr;
                phantomNode->prev_ = nullptr;
                delete pos.ptr_;
            }
            else
            {
                Node *right = pos.ptr_->next_;
                Node *left = pos.ptr_->prev_;
                left->next_ = right;
                right->prev_ = left;
                delete pos.ptr_;
            }
            --size_;
        }

        void push_back(const_reference value)
        {
            insert(end(), value);
        }

        void pop_back()
        {
            erase(--(end()));
        }

        void push_front(const_reference value)
        {
            insert(begin(), value);
        }

        void pop_front()
        {
            erase(begin());
        }

        void swap(list &other)
        {
            std::swap(phantomNode, other.phantomNode);
            std::swap(size_, other.size_);
        }

        void merge(list &other)
        {
            if (other.empty())
            {
                return;
            }
            if (empty())
            {
                swap(other);
                return;
            }
            auto itFirst = begin();
            auto itSecond = other.begin();
            while (itFirst != end() && itSecond != other.end())
            {
                if (*itFirst < *itSecond)
                {
                    ++itFirst;
                }
                else
                {
                    itFirst = insert(itFirst, *itSecond);
                    ++itSecond;
                }
            }
            while (itSecond != other.end())
            {
                push_back(*itSecond);
                ++itSecond;
            }
            other.clear();
        }

        void splice(const_iterator pos, list &other)
        {
            if (other.empty())
            {
                return;
            }
            for (auto it = other.begin(); it != other.end(); ++it)
            {
                insert(pos, *it);
            }
            other.clear();
        }

        void reverse() noexcept
        {
            list copy;
            for (auto it = begin(); it != end(); ++it)
            {
                copy.push_front(*it);
            }
            swap(copy);
        }

        void unique()
        {
            if (size_ <= 1)
            {
                return;
            }
            auto it = begin();
            ++it;
            for (; it != end(); ++it)
            {
                auto jt = it;
                --jt;
                if (*it == *(jt))
                {
                    erase(jt);
                }
            }
        }

        void sort()
        {
            for (auto it = begin(); it != end(); ++it)
            {
                for (auto jt = begin(); jt != end(); ++jt)
                {
                    if (*it < *jt)
                    {
                        std::swap(*it, *jt);
                    }
                }
            }
        }

        struct Node
        {
            value_type data_;
            Node *prev_;
            Node *next_;

            Node() : prev_(nullptr), next_(nullptr) {}
            Node(value_type data) : data_(data), prev_(nullptr), next_(nullptr) {}
        };

        class ListIterator
        {
        public:
            ListIterator() {}

            ListIterator(Node *ptr) : ptr_(ptr) {}

            value_type *operator->()
            {
                return &(ptr_->data_);
            }

            ListIterator &operator++()
            {
                ptr_ = ptr_->next_;
                return *this;
            }

            ListIterator operator++(int)
            {
                Node *copy(ptr_);
                ptr_ = ptr_->next_;
                return copy;
            }

            ListIterator &operator--()
            {
                ptr_ = ptr_->prev_;
                return *this;
            }

            ListIterator operator--(int)
            {
                Node *copy(ptr_);
                ptr_ = ptr_->prev_;
                return copy;
            }

            reference operator*()
            {
                return ptr_->data_;
            }

            bool operator==(const ListIterator &other) const
            {
                return ptr_ == other.ptr_;
            }

            bool operator!=(const ListIterator &other) const
            {
                return ptr_ != other.ptr_;
            }

            Node *ptr_;
        };

        class ListConstIterator
        {
        public:
            ListConstIterator() {}
            ListConstIterator(Node *ptr) : ptr_(ptr) {}

            const value_type *operator->()
            {
                return &(ptr_->data_);
            }

            ListConstIterator &operator++()
            {
                ptr_ = ptr_->next_;
                return *this;
            }

            ListConstIterator operator++(int)
            {
                Node *copy(ptr_);
                ptr_ = ptr_->next_;
                return copy;
            }

            ListConstIterator &operator--()
            {
                ptr_ = ptr_->prev_;
                return *this;
            }

            ListConstIterator operator--(int)
            {
                Node *copy(ptr_);
                ptr_ = ptr_->prev_;
                return copy;
            }

            const_reference operator*()
            {
                return ptr_->data_;
            }

            bool operator==(const ListConstIterator &other) const
            {
                return ptr_ == other.ptr_;
            }

            bool operator!=(const ListConstIterator &other) const
            {
                return ptr_ != other.ptr_;
            }

            Node *ptr_;
        };

    private:
        Node *phantomNode;
        size_type size_;
    };

} // namespaсe s21
#endif // CPP2_S21_CONTEINERS_1_S21_LIST_H