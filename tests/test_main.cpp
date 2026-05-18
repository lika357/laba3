#include <iostream>

#include "assert.hpp"
#include "tests.hpp"

int main()
{
    test_stack_constructor();
    test_stack_push();
    test_stack_pop();
    test_stack_top();
    test_stack_is_empty();
    test_stack_get_size();
    test_stack_operators();
    test_stack_list();
    test_stack_exceptions();

    test_queue_constructor();
    test_queue_enqueue();
    test_queue_dequeue();
    test_queue_front_back();
    test_queue_empty_and_size();
    test_queue_operators();
    test_queue_list();
    test_queue_exceptions();

    test_deque_push_front();
    test_deque_push_back();
    test_deque_pop_front();
    test_deque_pop_back();
    test_deque_front_back();
    test_deque_empty_and_size();
    test_deque_list();
    test_deque_exceptions();
    test_deque_operators();

    std::cout << "true " << get_true_tests() << "\n";
    std::cout << "false " << get_failed_tests() << "\n";

    return get_failed_tests();
}