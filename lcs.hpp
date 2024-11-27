#ifndef LCS
#define LCS

#include <string>

struct LCSResult
{
    std::string subseq;
    size_t length;
};

LCSResult* calculate_lcs(const char* str1, const char* str2, bool shouldCalculateSubseq = false);

#endif