#pragma once
#include "linked_list.hpp"

template <typename T>
class Queue : private LinkedList<T>
{
   public:
    Queue() : LinkedList<T>()
    {
    }
};