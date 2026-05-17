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
};