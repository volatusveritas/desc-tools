#ifndef DESCTOOLS_ERROR_HPP_
#define DESCTOOLS_ERROR_HPP_

enum class ErrorCode
{
    // Command Line Arguments
    INSUFFICIENT_ARGUMENTS,
    INVALID_ARGUMENT,

    // File I/O
    FILE_READ_FAILURE,
};


void issueError(ErrorCode e, const char *details = "");

#endif  // DESCTOOLS_ERROR_HPP_
