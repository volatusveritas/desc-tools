#include "alias.hpp"
#include "cstr.hpp"


bool
validateAlias(const char *str, Aliases::alias *aliasList)
{
    using namespace Aliases;
    for (alias *alias {aliasList}; *alias != ALIAS_END; alias++)
    {
        if (cstrEquals(str, *alias)) return true;
    }

    return false;
}
