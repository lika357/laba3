#pragma once
#include "linked_list.hpp"

template <typename T>
class Queue : private LinkedList<T>
{
   public:
    Queue() : LinkedList<T>()
    {
    }
    void Enqueue(T item)
    {
        this->Append(item);
    }
    T Dequeue()
    {
        if (this->GetLength() == 0)
        {
            throw InvalidArgument{};
        }

        T val = this->GetFirst();

        LinkedList<T> temp;
        for (size_t i = 1; i < this->GetLength(); i++)
        {
            temp.Append(this->Get(i));
        }

        LinkedList<T>& base = *this;

        base = temp;

        return val;
    }
    T Front() const
    {
        if (this->GetLength() == 0)
        {
            throw InvalidArgument{};
        }
        return this->GetFirst();
    }
    T Back() const
    {
        if (this->GetLength() == 0)
        {
            throw InvalidArgument{};
        }
        return this->GetLast();
    }
    bool IsEmpty() const
    {
        return this->GetLength() == 0;
    }

    size_t GetSize() const
    {
        return this->GetLength();
    }
    void operator+=(T item)
    {
        this->Enqueue(item);
    }

    void operator--()
    {
        this->Dequeue();
    }

    T operator()()
    {
        return this->Front();
    }
};