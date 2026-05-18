#pragma once
#include "array_sequence.hpp"
#include "concepts.hpp"
#include "list_sequence.hpp"

template <template <typename> class Container, typename T>
    requires Stackable<Container<T>>
class Stack
{
   private:
    Container<T> c;

   public:
    Stack()
    {
    }

    void Push(const T& val)
    {
        c.PushBack(val);
    }

    T Pop()
    {
        if (c.GetLength() == 0)
        {
            throw InvalidArgument{};
        }
        T val = c.Back();
        c.PopBack();
        return val;
    }

    T& Top()
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
        Push(v);
    }
    void operator--()
    {
        Pop();
    }
    T& operator()()
    {
        return Top();
    }
};

template <typename T>
using ArrayStack = Stack<ArraySequence, T>;

template <typename T>
using ListStack = Stack<ListSequence, T>;