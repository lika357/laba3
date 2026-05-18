
#pragma once
#include "array_sequence.hpp"
#include "concepts.hpp"
#include "list_sequence.hpp"

template <template <typename> class Container, typename T>
    requires Queueable<Container<T>>
class Queue
{
   private:
    Container<T> c;

   public:
    Queue()
    {
    }

    void Enqueue(const T& val)
    {
        c.PushBack(val);
    }

    T Dequeue()
    {
        if (c.GetLength() == 0)
        {
            throw InvalidArgument{};
        }
        T val = c.Front();
        c.PopFront();
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
        Enqueue(v);
    }
    void operator--()
    {
        Dequeue();
    }
    T& operator()()
    {
        return Front();
    }
};
template <typename T>
using ArrayQueue = Queue<ArraySequence, T>;

template <typename T>
using ListQueue = Queue<ListSequence, T>;