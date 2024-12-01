/**
 * Christian Marcellino
 * COP4534 Project 5
 * 11/30/2024
 *
 * Tools for determining a strings longest common substring.
 */

#ifndef LCS
#define LCS

#include <string>

struct LCSResult
{
    std::string subseq;
    size_t length;

    LCSResult();
};

LCSResult* calculate_lcs(const char* str1, const char* str2, bool shouldCalculateSubseq = false);

#endif