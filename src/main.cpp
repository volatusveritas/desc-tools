#include <cstdlib>
#include <cstring>
#include <iostream>

#include "context.hpp"
#include "cstr.hpp"


Context context {};


void
helpExternal()
{
    std::cout <<
    "-h, --help -- this help message\n"
    "-f <path>, --file <path> -- specify initial file path\n";

    std::exit(EXIT_SUCCESS);
}


void
consumeArgs(int argc, char *argv[])
{
    while (argc > 0)
    {
        if (argv[0][0] == '-' && std::strlen(argv[0]) > 1)
        {
            argv[0]++;

            if (cstrEquals(argv[0], "h") || cstrEquals(argv[0], "-help"))
                helpExternal();
            else if (cstrEquals(argv[0], "f") || cstrEquals(argv[0], "-file"))
            {
                if (argc < 2)
                {
                    std::cout << "Insufficient arguments.\n";
                    std::exit(EXIT_FAILURE);
                }

                context.descFile.open(argv[1]);
                if (!context.descFile.is_open())
                {
                    std::cout <<
                        "Failed to open or read file '" << argv[1] << "'.\n";
                    std::exit(EXIT_FAILURE);
                }

                argc--; argv++;
            }
            else
            {
                std::cout << "Invalid option '" << argv[0] << "'.\n";
                std::exit(EXIT_FAILURE);
            }
        }
        else
        {
            std::cout << "Invalid argument '" << argv[0] << "'.\n";
            std::exit(EXIT_FAILURE);
        }

        argc--; argv++;
    }
}


int
main(int argc, char *argv[])
{
    argc--; argv++;
    if (argc > 0) consumeArgs(argc, argv);

    return EXIT_SUCCESS;
}
