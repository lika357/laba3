#include "../include/array_sequence.hpp"
#include "../include/deque.hpp"
#include "../include/list_sequence.hpp"
#include "../include/queue.hpp"
#include "../include/stack.hpp"
#include "assert.hpp"

void test_stack_constructor()
{
    ArrayStack<int> s;
    ListStack<int> s2;
    assert_func(true);
}

void test_stack_push()
{
    ArrayStack<int> s;
    s.Push(10);
    s.Push(20);
    assert_func(true);
}

void test_stack_pop()
{
    ArrayStack<int> s;
    s.Push(10);
    s.Push(20);

    int val = s.Pop();
    assert_func(val == 20);

    val = s.Pop();
    assert_func(val == 10);
}

void test_stack_top()
{
    ArrayStack<int> s;
    s.Push(10);
    s.Push(20);

    assert_func(s.Top() == 20);

    s.Top() = 30;
    assert_func(s.Top() == 30);
}

void test_stack_is_empty()
{
    ArrayStack<int> s;
    assert_func(s.IsEmpty() == true);

    s.Push(10);
    assert_func(s.IsEmpty() == false);
}

void test_stack_get_size()
{
    ArrayStack<int> s;
    assert_func(s.GetSize() == 0);

    s.Push(10);
    assert_func(s.GetSize() == 1);

    s.Push(20);
    assert_func(s.GetSize() == 2);
}

void test_stack_operators()
{
    ArrayStack<int> s;

    s += 10;
    assert_func(s() == 10);

    s += 20;
    assert_func(s() == 20);

    --s;
    assert_func(s() == 10);
}

void test_stack_list()
{
    ListStack<int> s;
    s.Push(10);
    s.Push(20);
    assert_func(s.Top() == 20);
    assert_func(s.Pop() == 20);
}

void test_stack_exceptions()
{
    ArrayStack<int> s;
    bool caught = false;

    try
    {
        s.Pop();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);

    caught = false;
    try
    {
        s.Top();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);
}

void test_queue_constructor()
{
    ArrayQueue<int> q;
    ListQueue<int> q2;
    assert_func(true);
}

void test_queue_enqueue()
{
    ArrayQueue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    assert_func(true);
}

void test_queue_dequeue()
{
    ArrayQueue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    int val = q.Dequeue();
    assert_func(val == 10);

    val = q.Dequeue();
    assert_func(val == 20);

    val = q.Dequeue();
    assert_func(val == 30);
}

void test_queue_front_back()
{
    ArrayQueue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    assert_func(q.Front() == 10);
    assert_func(q.Back() == 30);
}

void test_queue_empty_and_size()
{
    ArrayQueue<int> q;
    assert_func(q.IsEmpty() == true);
    assert_func(q.GetSize() == 0);

    q.Enqueue(10);
    assert_func(q.IsEmpty() == false);
    assert_func(q.GetSize() == 1);
}

void test_queue_operators()
{
    ArrayQueue<int> q;

    q += 10;
    assert_func(q() == 10);

    q += 20;
    assert_func(q() == 10);

    --q;
    assert_func(q() == 20);
}

void test_queue_list()
{
    ListQueue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    assert_func(q.Front() == 10);
    assert_func(q.Dequeue() == 10);
}

void test_queue_exceptions()
{
    ArrayQueue<int> q;
    bool caught = false;

    try
    {
        q.Dequeue();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);

    caught = false;
    try
    {
        q.Front();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);

    caught = false;
    try
    {
        q.Back();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);
}

void test_deque_push_front()
{
    ArrayDeque<int> d;
    d.PushFront(10);
    d.PushFront(20);
    assert_func(true);
}

void test_deque_push_back()
{
    ArrayDeque<int> d;
    d.PushBack(10);
    d.PushBack(20);
    assert_func(true);
}

void test_deque_pop_front()
{
    ArrayDeque<int> d;
    d.PushBack(10);
    d.PushBack(20);
    d.PushBack(30);

    int val = d.PopFront();
    assert_func(val == 10);
}

void test_deque_pop_back()
{
    ArrayDeque<int> d;
    d.PushBack(10);
    d.PushBack(20);
    d.PushBack(30);

    int val = d.PopBack();
    assert_func(val == 30);
}

void test_deque_front_back()
{
    ArrayDeque<int> d;
    d.PushBack(10);
    d.PushBack(20);

    assert_func(d.Front() == 10);
    assert_func(d.Back() == 20);
}

void test_deque_empty_and_size()
{
    ArrayDeque<int> d;
    assert_func(d.IsEmpty() == true);
    assert_func(d.GetSize() == 0);

    d.PushBack(10);
    assert_func(d.IsEmpty() == false);
    assert_func(d.GetSize() == 1);
}

void test_deque_list()
{
    ListDeque<int> d;
    d.PushBack(10);
    d.PushFront(5);
    assert_func(d.Front() == 5);
    assert_func(d.Back() == 10);
}

void test_deque_exceptions()
{
    ArrayDeque<int> d;
    bool caught = false;

    try
    {
        d.PopFront();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);

    caught = false;
    try
    {
        d.PopBack();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);

    caught = false;
    try
    {
        d.Front();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);

    caught = false;
    try
    {
        d.Back();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);
}

void test_deque_operators()
{
    ArrayDeque<int> d;

    d += 10;
    assert_func(d() == 10);

    d += 20;
    assert_func(d() == 20);

    --d;
    assert_func(d() == 10);
}