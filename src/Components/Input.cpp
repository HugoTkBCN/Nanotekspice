/*
** EPITECH PROJECT, 2020
** Input
** File description:
** cpp
*/

#include <iostream>
#include "Input.hpp"

namespace nts
{
    Input::Input() : AComponent("input", 1)
    {
        link[0] = 0;
    }

    Input::~Input()
    {
    }
}
