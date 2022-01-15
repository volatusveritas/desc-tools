#include "command.hpp"

#include <cstring>
#include <iostream>

#include "textpowertools/ansi.hpp"

#include "alias.hpp"
#include "context.hpp"


;


void
printPrompt(const Context &context)
{
    using namespace TextPowertools;

    std::cout << "dtools (";

    switch (context.viewMode)
    {
        case ViewMode::NORMAL:
        {
            ansiForegroundColor(ANSI_COLOR::BRIGHT_GREEN);
            std::cout << "Normal";
        } break;

        case ViewMode::EXPLORE:
        {
            ansiForegroundColor(ANSI_COLOR::BRIGHT_YELLOW);
            std::cout << "Explore";
        } break;
    }

    ansiResetForeground();
    std::cout << ") $ ";
}


void
getCommand(const Context &context)
{
    printPrompt(context);
}
