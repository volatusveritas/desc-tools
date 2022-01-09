#include <cstdlib>
#include <cstring>
#include <iostream>

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
    while (argCount > 0)
    {
        if (argValues[0][0] == '-' && std::strlen(argValues[0]) > 1)
        {
            argValues[0]++;

            if (
                cstrEquals(argValues[0], "h")
                || cstrEquals(argValues[0], "-help")
            ) helpExternal();
            else if (
                cstrEquals(argValues[0], "f")
                || cstrEquals(argValues[0], "-file")
            ) {
                if (argCount >= 2)
                {
                    openDescFile(argValues[1]);
                    argCount--; argValues++;
                }

                else issueError(ErrorCode::INSUFFICIENT_ARGUMENTS);
            }
            else
            {
                if (argValues[0][0] == '-')
                {
                    argValues[0]++;

                    if (argValues[0][0] == '\0')
                        issueError(ErrorCode::INVALID_ARGUMENT, "--");
                }

                issueError(ErrorCode::UNKNOWN_OPTION, argValues[0]);
            }
        }

        else issueError(ErrorCode::INVALID_ARGUMENT, argValues[0]);

        argCount--; argValues++;
    }
}


int
main(int argCount, char *argValues[])
{
    argCount--; argValues++;
    if (argCount > 0) consumeArgs(argCount, argValues);

    return EXIT_SUCCESS;
}
