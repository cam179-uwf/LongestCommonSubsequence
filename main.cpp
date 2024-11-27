#include <iostream>
#include <string>
#include <fstream>

#include "lcs.hpp"

int main(int argc, char** argv)
{
    std::ifstream ifs("twoStrings.txt");
    std::string str1;
    std::string str2;

    std::getline(ifs, str1);
    std::getline(ifs, str2);

    std::cout << "String1: " << str1.length() << std::endl;
    std::cout << "String2: " << str2.length() << std::endl;

    auto result = calculate_lcs("const a = 0;", "const b = 0;");
    std::cout << result->subseq << std::endl;
    std::cout << result->length << std::endl;
    delete result;
}