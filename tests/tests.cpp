#include "../include/array_sequence.hpp"
#include "../include/list_sequence.hpp"
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