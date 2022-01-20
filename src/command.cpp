#include "command.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <vector>


namespace Command
{
    std::string cmdStr;


    std::string_view
    extractArg(std::string_view &src, char delim = ' ')
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
    getCmdArgs()
    {
        std::getline(std::cin, cmdStr);
        std::string_view cmdView {cmdStr};

        std::vector<std::string_view> argList;

        while (!stripView(cmdView).empty())
        {
            if (cmdView.front() == '"')
            {
                cmdView.remove_prefix(1);
                if (!cmdView.empty())
                {
                    argList.push_back(extractArg(cmdView, '"'));
                }
            }
            else
            {
                argList.push_back(extractArg(cmdView));
            }
        }

        return argList;
    }
}  // namespace Command
