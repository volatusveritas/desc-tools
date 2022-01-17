#ifndef DESCTOOLS_COMMAND_HPP_
#define DESCTOOLS_COMMAND_HPP_

#include <iostream>
#include <vector>

namespace Command
{
    std::vector<std::string_view> getArguments(std::string_view ln);
}  // namespace Command

#endif  // DESCTOOLS_COMMAND_HPP_
