#ifndef DESCTOOLS_CONTEXT_HPP_
#define DESCTOOLS_CONTEXT_HPP_

#include <fstream>


enum class ViewMode
{
    NORMAL,
    EXPLORE,
};


struct Context
{
    ViewMode viewMode {ViewMode::NORMAL};
    std::ifstream descFile;
};

#endif
