#include "command.hpp"

#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "textpowertools/ansi.hpp"

#include "alias.hpp"
#include "context.hpp"

namespace Command
{
    std::pair<std::string_view, std::string_view>
    splitStringView(std::string_view str, char v)
    {
        size_t c = str.find_first_of(v);
        return {
            str.substr(0, c),
            c == std::string_view::npos ? "" : str.substr(c + 1),
        };
    }

    std::vector<std::string_view>
    getArguments(std::string_view ln)
    {
        std::vector<std::string_view> ret;
        for (;;)
        {
            while (!ln.empty() && ln.front() == ' ') ln.remove_prefix(1);
            if (ln.empty()) return ret;

            const auto [arg, nln] = ln.front() == '\"'
                                  ? splitStringView(ln.substr(1), '\"')
                                  : splitStringView(ln, ' ');

            ret.push_back(arg);
            ln = nln;
        }
    }
}  // namespace Command
