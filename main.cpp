/*
** EPITECH PROJECT, 2020
** main
** File description:
** cpp
*/

#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include "Prompt.hpp"
#include "IComponent.hpp"
#include "Core.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
    try {
        nts::Prompt Prompt(ac, av);
        Prompt.run();
    } catch(std::exception &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}
