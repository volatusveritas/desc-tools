#define _CRT_SECURE_NO_WARNINGS

#include "command.hpp"

#include <stdexcept>
#include <string>
#include <string_view>

#include "textpowertools/ansi.hpp"

#include "alias.hpp"
#include "context.hpp"

namespace Command
{
    std::string_view
    get_until(std::string_view &i, std::string_view v)
    {
        auto c = i.find_first_of(v);
        auto ret = i.substr(0, c);

        i = c == std::string_view::npos
          ? ""
          : i.substr(c + 1);

        return ret;
    }

    std::string_view
    popArgument(std::string_view &ln)
    {
        while (ln.substr(0, 1) == " ")
        {
            ln.remove_prefix(1);
        }

        if (ln.empty())
        {
            return "";
        }

        if (ln.front() == '\"')
        {
            ln.remove_prefix(1);
            return get_until(ln, "\"");
        }

        return get_until(ln, " ");
    }
}  // namespace Command
