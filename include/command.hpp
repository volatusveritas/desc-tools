#ifndef DESCTOOLS_COMMAND_HPP_
#define DESCTOOLS_COMMAND_HPP_

namespace Command
{
    void initializeCommandBuffer();

    void destroyCommandBuffer();

    void getCommand();

    char *popArgument();
}  // namespace Command

#endif  // DESCTOOLS_COMMAND_HPP_
