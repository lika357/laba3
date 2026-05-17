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

    std::cout << "true " << get_true_tests() << "\n";
    std::cout << "false " << get_failed_tests() << "\n";

    return get_failed_tests();
}