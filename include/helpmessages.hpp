#ifndef DESCTOOLS_HELPMESSAGES_HPP_
#define DESCTOOLS_HELPMESSAGES_HPP_

namespace HelpMessages
{
    using help_message = const char * const;


    constexpr help_message EXTERNAL {
        "-h, -hp, --help -- display this help message\n"
        "-f, -fl, --file <path> -- specify initial descfile\n"
        "-v, -vs, --version -- display current product version\n"
    };

    constexpr help_message NORMAL {
        "h, hp, help -- display this help message\n"
        "o, op, open <path> -- open the specified descfile\n"
        "c, ct, context -- display the current context\n"
        "l, ls, list -- list all tags in the current descfile\n"
        "r, rs, reset -- clear screen and display the current context\n"
        "f, fd, find <name> -- find a definition with the specified name\n"
        "e, ep, explore -- enter Explore mode\n"
        "q, qt, quit -- quit Desctools\n"
    };

    constexpr help_message EXPLORE {
        "f, fd, find <name> -- find a definition with the specified name\n"
        "n, nt, next -- jump forward to the next definition available\n"
        "p, pv, previous -- jump back to the next definition available\n"
        "q, qt, quit -- quit Explore mode\n"
    };
}  // namespace HelpMessages

#endif  // DESCTOOLS_HELPMESSAGES_HPP_
