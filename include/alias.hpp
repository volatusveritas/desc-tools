#ifndef DESCTOOLS_ALIAS_HPP_
#define DESCTOOLS_ALIAS_HPP_

namespace Aliases
{
    using alias = const char * const;


    constexpr alias ALIAS_END {""};


    namespace External
    {
        constexpr alias HELP    [] {"-h", "-hp", "--help",    ALIAS_END};
        constexpr alias FILE    [] {"-f", "-fl", "--file",    ALIAS_END};
        constexpr alias VERSION [] {"-v", "-vs", "--version", ALIAS_END};
    }  // namespace External


    namespace Normal
    {
        constexpr alias HELP    [] {"h", "hp", "help",     ALIAS_END};
        constexpr alias OPEN    [] {"o", "op", "open",     ALIAS_END};
        constexpr alias CONTEXT [] {"c", "ct", "context",  ALIAS_END};
        constexpr alias LIST    [] {"l", "ls", "list",     ALIAS_END};
        constexpr alias RESET   [] {"r", "rs", "reset",    ALIAS_END};
        constexpr alias FIND    [] {"f", "fd", "find",     ALIAS_END};
        constexpr alias EXPLORE [] {"e", "ep", "explore",  ALIAS_END};
        constexpr alias QUIT    [] {"q", "qt", "quit",     ALIAS_END};
    }  // namespace Normal


    namespace Explore
    {
        constexpr alias FIND     [] {"f", "fd", "find",     ALIAS_END};
        constexpr alias NEXT     [] {"n", "nt", "next",     ALIAS_END};
        constexpr alias PREVIOUS [] {"p", "pv", "previous", ALIAS_END};
        constexpr alias QUIT     [] {"q", "qt", "quit",     ALIAS_END};
    }  // namespace Explore
}  // namespace Aliases


bool validateAlias(const char *str, Aliases::alias *aliasList);

#endif  // DESCTOOLS_ALIAS_HPP_
