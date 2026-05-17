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