#include <cstdlib>
#include <cstring>
#include <iostream>

#include "alias.hpp"
#include "context.hpp"
#include "cstr.hpp"
#include "error.hpp"


static Context context {};


void
helpExternal()
{
    std::cout <<
    "-h, --help -- display this help message\n"
    "-f <path>, --file <path> -- specify initial file path\n";

    std::exit(EXIT_SUCCESS);
}


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
consumeArgs(int argCount, char *argValues[])
{
    if (argValues[0][0] != '-' || argValues[0][1] == '\0')
    {
        issueError(ErrorCode::INVALID_ARGUMENT, argValues[0]);
    }

    if (validateAlias(argValues[0], Aliases::External::HELP))
    {
        helpExternal();
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


void
getCommand()
{
}


int
main(int argCount, char *argValues[])
{
    argCount--; argValues++;
    while (argCount > 0) consumeArgs(argCount, argValues);

    return EXIT_SUCCESS;
}
