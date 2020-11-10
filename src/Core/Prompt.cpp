/*
** EPITECH PROJECT, 2020
** Prompt
** File description:
** cpp
*/

#include <iostream>
#include "Prompt.hpp"

namespace nts
{
    static bool	quit = false;

    Prompt::Prompt(int ac, char **av) : core(ac, av), input(), exist(false)
    {
        commands["display"] = std::bind(&Prompt::display, this);
        commands["exit"] = std::bind(&Prompt::exit, this);
        commands["loop"] = std::bind(&Prompt::loop, this);
        commands["dump"] = std::bind(&Prompt::dump, this);
        commands["setInput"] = std::bind(&Prompt::setInput, this);
        commands["simulate"] = std::bind(&Prompt::simulate, this);
    }

    Prompt::~Prompt()
    {
    }

    void Prompt::exit()
    {
        exist = true;
    }

    void Prompt::display() const
    {
        core.display();
    }

    void Prompt::setInput()
    {
        core.setInput(input.substr(0, input.find("=")), 
                        (Tristate)std::atoi(input.substr(input.find("=") + 1, input.size()).c_str()));
    }

    void Prompt::simulate()
    {
        core.compute();
        core.invertClock();
    }

    static void sigSimulate(int tmp)
    {
        (void)tmp;
        quit = true;
    }

    void Prompt::loop()
    {
        signal(SIGINT, sigSimulate);
        for (int end = 0; end == 0;) {
            if (quit) {
                simulate();
                std::cout << std::endl;
                end = 1;
            }
        }
    }

    void Prompt::dump() const
    {
        core.dumps();
    }

    void print_err()
    {
        std::cout << "la" << std::endl;
    }

    void Prompt::run()
    {
        commands["simulate"]();
        commands["display"]();
        while (!exist) {
            std::cout << "> ";
            if (!std::getline(std::cin, input)) {
                commands["exit"]();
                std::cout << "exit" << std::endl;
            } else {
                ((int)input.find("=") != -1) ? 
                commands["setInput"]() : ((commands.count(input)) != 0) ? 
                commands[input]() : (void)(std::cerr << "Error : Invalid commande : '" + input + "'" << std::endl);
            }
        }
    }
}
