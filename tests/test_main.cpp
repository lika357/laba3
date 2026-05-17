#include <iostream>

#include "assert.hpp"
#include "tests.hpp"

int main()
{
    test_stack_constructor();
    test_stack_push();
    test_stack_pop();
    test_array_sequence_resize();
    test_list_sequence_resize();
    test_stack_peek();
    test_stack_is_empty();
    test_stack_get_size();
    test_stack_operators();
    test_queue_constructor();
    test_queue_enqueue();
    test_queue_dequeue();
    test_queue_front_back();

    std::cout << "true " << get_true_tests() << "\n";
    std::cout << "false " << get_failed_tests() << "\n";

    return get_failed_tests();
}