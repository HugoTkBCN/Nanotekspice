/*
** EPITECH PROJECT, 2020
** False
** File description:
** cpp
*/

#include "False.hpp"

namespace nts
{
    False::False() : AComponent("False", 1)
    {
        tristateValue = Tristate::FALSE;
        link[0] = 0;
    }

    False::~False()
    {
    }
}

