#include <iostream>
#include <fstream>
#include <string>

#include "part1.hpp"
#include "lcs.hpp"

bool try_print_part1()
{
    std::string str1;
    std::string str2;

    std::cout << "====================" << '\n';
    std::cout << "|      Part 1      |" << '\n';
    std::cout << "====================" << '\n';
    std::cout << std::endl;

    std::ifstream ifs("twoStrings.txt");

    if (!ifs.is_open())
    {
        std::cout << "Could not open twoStrings.txt." << std::endl;
        return false;
    }

    ifs >> str1;
    ifs >> str2;

    std::cout << "String 1 (length: " << str1.length() << "):" << std::endl;
    std::cout << str1 << '\n' << std::endl;

    std::cout << "String 2 (length: " << str2.length() << "):" << std::endl;
    std::cout << str1 << '\n' << std::endl;

    auto result = calculate_lcs(str1.c_str(), str2.c_str(), true);
    std::cout << "Longest Common Subsequence (length: " << result->length << "):" << std::endl;
    std::cout << result->subseq << std::endl;
    delete result;

    ifs.close();

    return true;
}