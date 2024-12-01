/**
 * Christian Marcellino
 * COP4534 Project 5
 * 11/30/2024
 */

#include <iostream>

#include "part1.hpp"
#include "part2.hpp"

int main(int argc, char** argv)
{
    if (!try_print_part1()) return EXIT_FAILURE;

    std::cout << std::endl;

    if (!try_print_part2()) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}