#pragma once
#include "array_sequence.hpp"

template <typename T>
class Stack : private ArraySequence<T>
{
   public:
    Stack() : ArraySequence<T>()
    {
    }
    void Push(T item)
    {
        this->Append(item);
    }
    T Pop()
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
    T Peek() const
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
};