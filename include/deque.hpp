
#pragma once
#include "array_sequence.hpp"
#include "concepts.hpp"
#include "list_sequence.hpp"

template <template <typename> class Container, typename T>
    requires Dequeable<Container<T>>
class Deque
{
   private:
    Container<T> c;

   public:
    Deque()
    {
    }

    void PushFront(const T& val)
    {
        c.PushFront(val);
    }

    void PushBack(const T& val)
    {
        c.PushBack(val);
    }

    T PopFront()
    {
        if (c.GetLength() == 0)
        {
            throw InvalidArgument{};
        }
        T val = c.Front();
        c.PopFront();
        return val;
    }

    T PopBack()
    {
        if (c.GetLength() == 0)
        {
            throw InvalidArgument{};
        }
        T val = c.Back();
        c.PopBack();
        return val;
    }

    T& Front()
    {
        if (c.GetLength() == 0)
        {
            throw InvalidArgument{};
        }
        return c.Front();
    }

    T& Back()
    {
        if (c.GetLength() == 0)
        {
            throw InvalidArgument{};
        }
        return c.Back();
    }

    bool IsEmpty() const
    {
        return c.GetLength() == 0;
    }

    size_t GetSize() const
    {
        return c.GetLength();
    }

    void operator+=(const T& v)
    {
        PushBack(v);
    }
    void operator--()
    {
        PopBack();
    }
    T& operator()()
    {
        return Back();
    }
};

template <typename T>
using ArrayDeque = Deque<ArraySequence, T>;

template <typename T>
using ListDeque = Deque<ListSequence, T>;