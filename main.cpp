#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "lcs.hpp"

char get_similarity(std::string& str1, std::string& str2)
{
    std::cout << std::fixed << std::setprecision(2);

    auto lcsResult = calculate_lcs(str1.c_str(), str2.c_str(), true);
    char result;

    // std::cout << lcsResult->length << " ";

    if (str1.size() > str2.size())
    {
        float a = str2.size() / (float)str1.size();
        float b = lcsResult->length / (float)str2.size();

        if (a >= 0.9 && b >= 0.9)
        {
            result = 'H';
        }
        else if (a >= 0.8 && b >= 0.8)
        {
            result = 'M';
        }
        else if (a >= 0.6 && b >= 0.5)
        {
            result = 'L';
        }
        else
        {
            result = 'D';
        }
    }
    else
    {
        float a = str1.size() / (float)str2.size();
        float b = lcsResult->length / (float)str1.size();

        if (a >= 0.9 && b >= 0.9)
        {
            result = 'H';
        }
        else if (a >= 0.8 && b >= 0.8)
        {
            result = 'M';
        }
        else if (a >= 0.6 && b >= 0.5)
        {
            result = 'L';
        }
        else
        {
            result = 'D';
        }
    }

    delete lcsResult;
    return result;
}

int main(int argc, char** argv)
{
    std::string str1;
    std::string str2;

    /**
     * Part 1
     */

    std::cout << "====================" << '\n';
    std::cout << "|      Part 1      |" << '\n';
    std::cout << "====================" << '\n';
    std::cout << std::endl;

    std::ifstream ifs("twoStrings.txt");

    if (!ifs.is_open())
    {
        std::cout << "Could not open twoStrings.txt." << std::endl;
        return EXIT_FAILURE;
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

    /**
     * Part 2
     */

    std::cout << std::endl;
    std::cout << "====================" << '\n';
    std::cout << "|      Part 2      |" << '\n';
    std::cout << "====================" << '\n';
    std::cout << std::endl;
    
    ifs.open("multiStrings.txt");

    if (!ifs.is_open())
    {
        std::cout << "Could not open multiStrings.txt." << std::endl;
        return EXIT_FAILURE;
    }

    int count;
    ifs >> count;

    std::getline(ifs, str1);

    auto initialIndex = ifs.tellg();
    auto currentIndex = initialIndex;
    bool shouldBreak = false;

    // header
    std::cout << "  ";
    for (int i = 0; i < count; ++i)
        std::cout << (i + 1) << " ";
    std::cout << std::endl;

    for (int y = 0; y < count; ++y)
    {
        ifs.seekg(currentIndex);
        std::getline(ifs, str1);

        shouldBreak = ifs.eof();
        currentIndex = ifs.tellg();

        ifs.clear();
        ifs.seekg(initialIndex);

        std::cout << (y + 1) << " ";

        for (int x = 0; x < count && !ifs.eof(); ++x)
        {
            std::getline(ifs, str2);

            char similarity = get_similarity(str1, str2);

            std::cout << similarity << " ";
        }

        std::cout << std::endl;

        if (shouldBreak) break;
    }

    return EXIT_SUCCESS;
}