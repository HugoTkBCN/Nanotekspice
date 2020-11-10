/*
** EPITECH PROJECT, 2020
** True
** File description:
** cpp
*/

#include "True.hpp"

namespace nts
{
    True::True() : AComponent("True", 1)
    {
        tristateValue = Tristate::TRUE;
        link[0] = 0;
    }

    True::~True()
    {
    }
}