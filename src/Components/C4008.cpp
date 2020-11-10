/*
** EPITECH PROJECT, 2020
** C4008
** File description:
** cpp
*/

#include "C4008.hpp"

namespace nts
{
    C4008::C4008() : AComponent("4008", 16)
    {
        initGates();
        initInPins();
        initOutPins();
        initOtherPins();
    }

    void C4008::initGates()
    {
    }

    void C4008::initInPins()
    {
    }

    void C4008::initOutPins()
    {
    }

    void C4008::initOtherPins()
    {
    }

    Tristate C4008::compute(size_t)
    {
        return (nts::Tristate::UNDEFINED);
    }

    Tristate C4008::computeOutput(size_t)
    {
        return (nts::Tristate::UNDEFINED);
    }

    Tristate C4008::computeInput(size_t)
    {
        return (nts::Tristate::UNDEFINED);
    }

}
