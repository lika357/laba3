#include "../include/array_sequence.hpp"
#include "../include/deque.hpp"
#include "../include/list_sequence.hpp"
#include "../include/queue.hpp"
#include "../include/stack.hpp"
#include "assert.hpp"

void test_stack_constructor()
{
    Stack<int> s;
    assert_func(true);
}
void test_stack_push()
{
    Stack<int> s;
    s.Push(10);
    s.Push(20);
    assert_func(true);
}
void test_stack_pop()
{
    Stack<int> s;
    s.Push(10);
    s.Push(20);

    int val = s.Pop();
    assert_func(val == 20);

    val = s.Pop();
    assert_func(val == 10);
}
void test_array_sequence_resize()
{
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> seq(arr);

    seq.Resize(3);
    assert_func(seq.GetLength() == 3);
    assert_func(seq.Get(0) == 1);
    assert_func(seq.Get(2) == 3);

    seq.Resize(5);
    assert_func(seq.GetLength() == 5);
}

void test_list_sequence_resize()
{
    int arr[] = {1, 2, 3};
    ListSequence<int> seq(arr);

    seq.Resize(2);
    assert_func(seq.GetLength() == 2);
    assert_func(seq.Get(0) == 1);
}
void test_stack_peek()
{
    Stack<int> s;
    s.Push(10);
    s.Push(20);

    int val = s.Peek();
    assert_func(val == 20);

    val = s.Peek();
    assert_func(val == 20);
}
void test_stack_is_empty()
{
    Stack<int> s;
    assert_func(s.IsEmpty() == true);

    s.Push(10);
    assert_func(s.IsEmpty() == false);
}
void test_stack_get_size()
{
    Stack<int> s;
    assert_func(s.GetSize() == 0);

    s.Push(10);
    assert_func(s.GetSize() == 1);

    s.Push(20);
    assert_func(s.GetSize() == 2);
}
void test_stack_operators()
{
    Stack<int> s;

    s += 10;
    assert_func(s() == 10);

    s += 20;
    assert_func(s() == 20);

    --s;
    assert_func(s() == 10);
}

void test_queue_constructor()
{
    Queue<int> q;
    assert_func(true);
}
void test_queue_enqueue()
{
    Queue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    assert_func(true);
}
void test_queue_dequeue()
{
    Queue<int> q;
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
    Queue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    assert_func(q.Front() == 10);
    assert_func(q.Back() == 30);
}
void test_queue_empty_and_size()
{
    Queue<int> q;
    assert_func(q.IsEmpty() == true);
    assert_func(q.GetSize() == 0);

    q.Enqueue(10);
    assert_func(q.IsEmpty() == false);
    assert_func(q.GetSize() == 1);
}
void test_queue_operators()
{
    Queue<int> q;

    q += 10;
    assert_func(q() == 10);

    q += 20;
    assert_func(q() == 10);

    --q;
    assert_func(q() == 20);
}
void test_stack_exceptions()
{
    Stack<int> s;
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
        s.Peek();
    }
    catch (const InvalidArgument&)
    {
        caught = true;
    }
    assert_func(caught);
}

void test_queue_exceptions()
{
    Queue<int> q;
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
    Deque<int> d;
    d.PushFront(10);
    d.PushFront(20);
    assert_func(true);
}

void test_deque_push_back()
{
    Deque<int> d;
    d.PushBack(10);
    d.PushBack(20);
    assert_func(true);
}

void test_deque_pop_front()
{
    Deque<int> d;
    d.PushBack(10);
    d.PushBack(20);
    d.PushBack(30);

    int val = d.PopFront();
    assert_func(val == 10);
}

void test_deque_pop_back()
{
    Deque<int> d;
    d.PushBack(10);
    d.PushBack(20);
    d.PushBack(30);

    int val = d.PopBack();
    assert_func(val == 30);

    val = d.PopBack();
    assert_func(val == 20);
}

void test_deque_front_back()
{
    Deque<int> d;
    d.PushBack(10);
    d.PushBack(20);

    assert_func(d.Front() == 10);
    assert_func(d.Back() == 20);
}

void test_deque_empty_and_size()
{
    Deque<int> d;
    assert_func(d.IsEmpty() == true);
    assert_func(d.GetSize() == 0);

    d.PushBack(10);
    assert_func(d.IsEmpty() == false);
    assert_func(d.GetSize() == 1);
}

void test_deque_exceptions()
{
    Deque<int> d;
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
    Deque<int> d;

    d += 10;
    assert_func(d() == 10);

    d += 20;
    assert_func(d() == 20);

    --d;
    assert_func(d() == 10);
}