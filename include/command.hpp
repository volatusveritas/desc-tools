#ifndef DESCTOOLS_COMMAND_HPP_
#define DESCTOOLS_COMMAND_HPP_

#include <string_view>
#include <vector>


namespace Command
{
    std::vector<std::string_view> getArgs(std::string_view ln);
}  // namespace Command

#endif  // DESCTOOLS_COMMAND_HPP_
