#ifndef DESCTOOLS_CSTR_HPP
#define DESCTOOLS_CSTR_HPP_

#include <cstring>


inline bool
cstrEquals(const char *strA, const char *strB)
{
    return std::strcmp(strA, strB) == 0;
}

#endif  // DESCTOOLS_CSTR_HPP_
