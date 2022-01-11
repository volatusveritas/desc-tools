#include "error.hpp"

#include <cstdlib>
#include <iostream>


void
issueError(ErrorCode e, const char *details)
{
    switch (e)
    {
        case ErrorCode::INSUFFICIENT_ARGUMENTS:
        {
            std::cout <<
                "Insufficient arguments for '" << details << "' option.\n";
        } break;

        case ErrorCode::INVALID_ARGUMENT:
        {
            std::cout << "Invalid argument '" << details << "'.\n";
        } break;

        case ErrorCode::FILE_READ_FAILURE:
        {
            std::cout << "Faild to open or read file '" << details << "'.\n";
        } break;

        default:
        {
            std::cout << "Unknown error.\n";
        } break;
    }

    std::exit(EXIT_FAILURE);
}
