#pragma once
#include "array_sequence.hpp"
#include "linked_list.hpp"

template <typename T>
class Deque : private ArraySequence<T>
{
   public:
    Deque() : ArraySequence<T>()
    {
    }
    void PushFront(T item)
    {
        this->Prepend(item);
    }
    void PushBack(T item)
    {
        this->Append(item);
    }
    T PopFront()
    {
        if (this->GetLength() == 0)
        {
            throw InvalidArgument{};
        }

        T val = this->GetFirst();

        ArraySequence<T> temp;
        for (size_t i = 1; i < this->GetLength(); i++)
        {
            temp.Append(this->Get(i));
        }
        ArraySequence<T>& base = *this;
        base = temp;
        return val;
    }
    T PopBack()
    {
        if (this->GetLength() == 0)
        {
            throw InvalidArgument{};
        }

        T val = this->GetLast();
        size_t oldSize = this->GetLength();
        this->Resize(oldSize - 1);
        return val;
    }
    bool IsEmpty() const
    {
        return this->GetLength() == 0;
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
    size_t GetSize() const
    {
        return this->GetLength();
    }
    void operator+=(T item)
    {
        this->PushBack(item);
    }
    void operator--()
    {
        this->PopBack();
    }
    T operator()()
    {
        return this->Back();
    }
};