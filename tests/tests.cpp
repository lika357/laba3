#include "../include/array_sequence.hpp"
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