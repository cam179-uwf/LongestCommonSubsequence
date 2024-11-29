#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "part2.hpp"
#include "lcs.hpp"

bool try_print_part2()
{
    std::string str1;
    std::string str2;

    std::cout << "====================" << '\n';
    std::cout << "|      Part 2      |" << '\n';
    std::cout << "====================" << '\n';
    std::cout << std::endl;
    
    std::ifstream ifs("multiStrings.txt");

    if (!ifs.is_open())
    {
        std::cout << "Could not open multiStrings.txt." << std::endl;
        return false;
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

            if (x > y) 
            {
                char similarity = get_similarity(str1, str2);
                std::cout << similarity << " ";
            }
            else 
            {
                std::cout << "- ";
            }
        }

        std::cout << std::endl;

        if (shouldBreak) break;
    }

    ifs.close();

    return true;
}

char get_similarity(std::string& str1, std::string& str2)
{
    std::cout << std::fixed << std::setprecision(2);

    auto lcsResult = calculate_lcs(str1.c_str(), str2.c_str(), true);
    char result;

    if (str1.size() > str2.size())
    {
        float smallPercentageOfLarge = str2.size() / (float)str1.size();
        float subseqPercentageOfSmall = lcsResult->length / (float)str2.size();

        if (smallPercentageOfLarge >= 0.9 && subseqPercentageOfSmall >= 0.9)
        {
            result = 'H';
        }
        else if (smallPercentageOfLarge >= 0.8 && subseqPercentageOfSmall >= 0.8)
        {
            result = 'M';
        }
        else if (smallPercentageOfLarge >= 0.6 && subseqPercentageOfSmall >= 0.5)
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
        float smallPercentageOfLarge = str1.size() / (float)str2.size();
        float subseqPercentageOfSmall = lcsResult->length / (float)str1.size();

        if (smallPercentageOfLarge >= 0.9 && subseqPercentageOfSmall >= 0.9)
        {
            result = 'H';
        }
        else if (smallPercentageOfLarge >= 0.8 && subseqPercentageOfSmall >= 0.8)
        {
            result = 'M';
        }
        else if (smallPercentageOfLarge >= 0.6 && subseqPercentageOfSmall >= 0.5)
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