#include "command.hpp"

#include <string_view>
#include <vector>


namespace Command
{
    std::string_view
    getArg(std::string_view &src, char delim = ' ')
    {
        std::string_view arg;

        auto delimPos {src.find_first_of(delim)};
        if (delimPos != std::string_view::npos)
        {
            arg = src.substr(0, delimPos);
            src.remove_prefix(delimPos + 1);
        }
        else
        {
            arg = src;
            src = "";
        }

        return arg;
    }


    std::string_view &
    stripView(std::string_view &view)
    {
        while (!view.empty() && view.front() == ' ') view.remove_prefix(1);
        return view;
    }


    std::vector<std::string_view>
    getArgs(std::string_view line)
    {
        std::vector<std::string_view> args;

        while (!stripView(line).empty())
        {
            if (line.front() == '"')
            {
                line.remove_prefix(1);
                if (!line.empty()) args.push_back(getArg(line, '"'));
            }
            else
            {
                args.push_back(getArg(line));
            }
        }

        return args;
    }
}  // namespace Command
