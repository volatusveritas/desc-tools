#define _CRT_SECURE_NO_WARNINGS

#include "command.hpp"

#include <cstdlib>

#include "textpowertools/ansi.hpp"

#include "alias.hpp"
#include "context.hpp"


#define BUF_MAX SHRT_MAX


namespace Command
{
    char *commandBuffer {nullptr};
    char *currentArgument {nullptr};
    char *nextArgumentAnchor {nullptr};


    void
    initializeCommandBuffer()
    {
        commandBuffer = new char[BUF_MAX];
        currentArgument = new char[BUF_MAX];
    }


    void
    destroyCommandBuffer()
    {
        delete[] commandBuffer;
        delete[] currentArgument;
    }


    void
    advanceAnchor(char *startPosition)
    {
        for (char *i {startPosition}; i != '\0'; i++)
        {
            if (*i != ' ')
            {
                nextArgumentAnchor = i;
                return;
            }
        }

        nextArgumentAnchor = nullptr;
    }


    void
    getCommand()
    {
        std::fgets(commandBuffer, BUF_MAX, stdin);
        nextArgumentAnchor = commandBuffer;

        if (*nextArgumentAnchor == ' ') advanceAnchor(nextArgumentAnchor);
    }


    char *
    popArgument()
    {
        if (nextArgumentAnchor == nullptr) return nullptr;

        char *nextArgumentEnd {std::strchr(nextArgumentAnchor, ' ')};
        if (nextArgumentEnd != nullptr)
        {
            std::ptrdiff_t argumentSize {nextArgumentEnd - nextArgumentAnchor};

            std::strncpy(currentArgument, nextArgumentAnchor, argumentSize);
            currentArgument[argumentSize + 1] = '\0';

            advanceAnchor(nextArgumentEnd);
        }
        else
        {
            std::strcpy(currentArgument, nextArgumentAnchor);
            nextArgumentAnchor = nullptr;
        }

        return currentArgument;
    }
}  // namespace Command
