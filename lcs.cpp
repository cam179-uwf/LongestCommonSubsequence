/**
 * Christian Marcellino
 * COP4534 Project 5
 * 11/30/2024
 *
 * Tools for determining a strings longest common substring.
 */

#include "lcs.hpp"

#include <iostream>
#include <cstring>
#include <stdexcept>

LCSResult::LCSResult()
{
    this->length = 0;
    this->subseq = "";
}

void reconstruct_subsequence_from_c_array(LCSResult& lcsResult, int* c, const char* str1, const char* str2, size_t len1, size_t len2)
{
    size_t i = 0, j = 0, width = len2 + 1;
    lcsResult.subseq = "";

    while (i < len1 && j < len2)
    {
        if (str1[i] == str2[j])
        {
            lcsResult.subseq += str1[i];
            ++i;
            ++j;
        }
        else if (c[j + (i + 1) * width] >= c[(j + 1) + i * width])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
}

LCSResult* calculate_lcs(const char* str1, const char* str2, bool shouldCalculateSubseq)
{
    if (str1 == nullptr || str2 == nullptr || str1[0] == '\0' || str2[0] == '\0')
        throw std::runtime_error("One of the strings is too large or too small or null.");

    size_t len1 = std::strlen(str1);
    size_t len2 = std::strlen(str2);

    if ((len1 <= 0 && len1 > 5000) || (len2 <= 0 && len2 > 5000))
    {
        throw std::runtime_error("One of the strings is too large or too small.");
    }

    LCSResult* lcsResult = new LCSResult();
    lcsResult->subseq = "";

    // initialize our c array
    size_t width = len2 + 1;
    size_t size = (len1 + 1) * width;
    
    int* c = new int[size];
    for (size_t i = 0; i < size; ++i)
        c[i] = 0;

    size_t i = len1 - 1, j = len2 - 1;

    while (true)
    {
        while (true)
        {
            if (str1[i] == str2[j])
            {
                c[j + i * width] = c[(j + 1) + (i + 1) * width] + 1;
            }
            else 
            {
                 c[j + i * width] = c[(j + 1) + i * width] > c[j + (i + 1) * width] ?
                    c[(j + 1) + i * width] :
                    c[j + (i + 1) * width];
            }

            if (j == 0) break;
            if (j > 0) --j;
        }

        j = len2 - 1;
        if (i == 0) break;
        if (i > 0) --i;
    }

    if (shouldCalculateSubseq)
        reconstruct_subsequence_from_c_array(*lcsResult, c, str1, str2, len1, len2);

    lcsResult->length = c[0];
    delete[] c;
    return lcsResult;
}