/*
** EPITECH PROJECT, 2020
** Clock
** File description:
** cpp
*/

#include "Clock.hpp"

namespace nts
{
    Clock::Clock() : AComponent("Clock", 1)
    {
        link[0] = 0;
    }

    Clock::~Clock()
    {
    }

    void Clock::setValue()
    {
        if (tristateValue == Tristate::FALSE)
            tristateValue = Tristate::TRUE;
        else
            tristateValue = Tristate::FALSE;
    }

}