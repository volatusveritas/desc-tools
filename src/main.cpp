#include <cstdlib>
#include <iostream>

#include "alias.hpp"
#include "command.hpp"
#include "context.hpp"
#include "error.hpp"
#include "helpmessages.hpp"
#include "productinfo.hpp"


static Context context {};


void
openDescFile(const char *filename)
{
    context.descFile.open(filename);

    if (!context.descFile.is_open())
    {
        issueError(ErrorCode::FILE_READ_FAILURE, filename);
    }
}


void
consumeExternalArgs(int argCount, char **argValues)
{
    argCount--; argValues++;

    while (argCount > 0)
    {
        if (argValues[0][0] != '-' || argValues[0][1] == '\0')
        {
            issueError(ErrorCode::INVALID_ARGUMENT, argValues[0]);
        }

        if (validateAlias(argValues[0], Aliases::External::HELP))
        {
            std::cout << HelpMessages::EXTERNAL;
            std::exit(EXIT_SUCCESS);
        }
        else if (validateAlias(argValues[0], Aliases::External::VERSION))
        {
            std::cout << "Desctools " << ProductInfo::version << '\n';
            std::exit(EXIT_SUCCESS);
        }
        else if (validateAlias(argValues[0], Aliases::External::FILE))
        {
            if (argCount >= 2)
            {
                openDescFile(argValues[1]);
                argCount--; argValues++;
            }
            else
            {
                issueError(ErrorCode::INSUFFICIENT_ARGUMENTS);
            }
        }
        else
        {
            issueError(ErrorCode::INVALID_ARGUMENT, argValues[0]);
        }

        argCount--; argValues++;
    }
}


int
main(int argCount, char *argValues[])
{
    consumeExternalArgs(argCount, argValues);

    return EXIT_SUCCESS;
}
