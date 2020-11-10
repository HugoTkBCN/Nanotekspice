/*
** EPITECH PROJECT, 2020
** Output
** File description:
** cpp
*/

#include <iostream>
#include "ExceptionComponent.hpp"
#include "Output.hpp"

namespace nts
{
    Output::Output() : AComponent("output", 1)
    {
        link[0] = 0;
    }

    Output::~Output()
    {
    }

    Tristate Output::compute(size_t pin)
    {
        checkPinNum(pin);
        if (pins[pin - 1] == nullptr)
            return Tristate::UNDEFINED;
        tristateValue = pins[pin - 1]->compute(link[pin - 1]);
        return (tristateValue);
    }

    void Output::setValue(Tristate)
    {
        throw ExceptionComponent("Component can not be set.");
    }

}
