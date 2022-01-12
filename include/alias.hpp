#ifndef DESCTOOLS_ALIAS_HPP_
#define DESCTOOLS_ALIAS_HPP_

namespace Aliases {

using alias = const char * const;


constexpr alias ALIAS_END {""};


namespace External {

constexpr alias HELP    [] {"-h", "--help", ALIAS_END};
constexpr alias FILE    [] {"-f", "--file", ALIAS_END};
/* constexpr alias VERSION [] {"-v", "--version", ALIAS_END}; */

}  // namespace External


namespace Normal {

/* constexpr alias HELP     [] {"h", "help",     ALIAS_END}; */
/* constexpr alias OPEN     [] {"o", "open",     ALIAS_END}; */
/* constexpr alias CONTEXT  [] {"c", "context",  ALIAS_END}; */
/* constexpr alias LIST     [] {"l", "list",     ALIAS_END}; */
/* constexpr alias RESET    [] {"r", "reset",    ALIAS_END}; */
/* constexpr alias FIND     [] {"f", "find",     ALIAS_END}; */
/* constexpr alias NEXT     [] {"n", "next",     ALIAS_END}; */
/* constexpr alias PREVIOUS [] {"p", "previous", ALIAS_END}; */
/* constexpr alias EXPLORE  [] {"e", "explore",  ALIAS_END}; */
/* constexpr alias QUIT     [] {"q", "quit",     ALIAS_END}; */

}  // namespace Normal


namespace Explore {

/* constexpr alias QUIT [] {"q", "quit", ALIAS_END}; */

}  // namespace Explore

}  // namespace Aliases


bool validateAlias(const char *str, Aliases::alias *aliasList);

#endif  // DESCTOOLS_ALIAS_HPP_
