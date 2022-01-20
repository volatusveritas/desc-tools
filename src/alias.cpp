#include "alias.hpp"

#include <cstring>


bool
validateAlias(const char *str, Aliases::alias *aliasList)
{
    using namespace Aliases;

    for (alias *aliasPtr {aliasList}; **aliasPtr != *ALIAS_END; aliasPtr++)
    {
        if (std::strcmp(str, *aliasPtr) == 0) return true;
    }

    return false;
}
